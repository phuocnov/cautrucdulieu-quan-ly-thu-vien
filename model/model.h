#include <iostream>
#include "schema_all.h"

#define MIN_RANGE 1000
#define MAX_RANGE 9999

using namespace std;

// Các hàm tái sử dụng
int randomInt(int min, int max){
    
   return rand() % (max-min +1); 
}

// Độc giả
namespace the_doc_gia{
    void Free(node_DanhSachTheDocGia* root){
        if(root == NULL)
            return;
        Free(root->left);
        Free(root->right);
    }
    int LeftOf(const TheDocGia value, const node_DanhSachTheDocGia* root){
        return value.maThe < root->data.maThe;
    }
    int RightOf(const TheDocGia value, const node_DanhSachTheDocGia* root){
        return value.maThe > root->data.maThe;
    }
    TheDocGia LeftMostValue(const node_DanhSachTheDocGia* root){
        while (root->left != NULL){
            root = root->left;
            return root->data;
        }
        return root->data;
    }

    void checkMaThe(TheDocGia &tdg, int arrayID[], int &arrayIDlength){
        bool isContinune = true;
        while(isContinune){
            if(arrayIDlength == 0){
                arrayIDlength++;
                arrayID[0] = tdg.maThe;
                isContinune = false;
            }
            else{
                for (int i = 0; i < arrayIDlength; i++)
                {
                    if(tdg.maThe == arrayID[i]){
                        tdg.maThe = randomInt(MIN_RANGE, MAX_RANGE);
                        break;
                    }
                    if(i == arrayIDlength - 1 && tdg.maThe != arrayID[i]){
                        isContinune = false;
                        arrayID[i+1] = tdg.maThe;
                        arrayIDlength++;
                        isContinune = false;
                        break;
                    }
                }
            }
            continue;
        }
    }

    TheDocGia Create(string ho, string ten, string phai, int arrayID[], int &arrayIDlength){
        TheDocGia tdg;
        tdg.ho = ho;
        tdg.ten = ten; 
        tdg.phai = phai;
        tdg.trangThaiThe = HOAT_DONG;
        tdg.maThe = randomInt(MIN_RANGE, MAX_RANGE);
        checkMaThe(tdg, arrayID, arrayIDlength);
        return tdg;
    }

    void Insert(node_DanhSachTheDocGia* &root, TheDocGia data){
        if(root == NULL){
            root = new node_DanhSachTheDocGia;
            root->left = NULL;
            root->right = NULL;
            root->data = data;
        }
        if(LeftOf(data, root)){
            Insert(root->left, data);
        }
        else if(RightOf(data, root)){
            Insert(root->right, data);
        }
    }

    node_DanhSachTheDocGia* NameSearch(node_DanhSachTheDocGia* root, string ho, string ten){
        if(root == NULL) return NULL;
        else{
            if(ten == root->data.ten && ho == root->data.ho) return root;
            else{
                NameSearch(root->left, ho, ten);
                NameSearch(root->right, ho, ten);
            } 
        }
        return NULL;
    }
    bool isAvailabe(int ID, int arrayID[], int size) {
        for (int i = 0; i < size; i++)
        {
            if(ID == arrayID[i]) return true;
        }
        return false;
    }
    node_DanhSachTheDocGia* IDSearch(node_DanhSachTheDocGia* root, int ID, int arrayID[], int &arrayIDlength){
        if(isAvailabe(ID, arrayID, arrayIDlength)){
            if(root == NULL || root->data.maThe == ID) return root;
            if(root->data.maThe > ID) return IDSearch(root->left, ID, arrayID, arrayIDlength);
            return IDSearch(root->right, ID, arrayID, arrayIDlength);
        }
        else{
            cout << "ID khong ton tai" << endl;
            return NULL;
        }
    }

    node_DanhSachTheDocGia* Edit(node_DanhSachTheDocGia* node, string ho, string ten, string  phai){
        node->data.ho = ho;
        node->data.ten = ten;
        node->data.phai = phai;
        
        return node;
    }

    void removeIDarray(int ID, int arrayID[], int &arrayIDlength){
        for (int i = 0; i < arrayIDlength; i++)
        {
            if(arrayID[i] == ID){
                for(int j = i; j < arrayIDlength; j++) arrayID[i] = arrayID[i+1];
                arrayIDlength--;
                break;
            }
        }
        
    }

    node_DanhSachTheDocGia* Delete(node_DanhSachTheDocGia*root, TheDocGia value, int arrayID[], int &arrayIDlength){
        if(root == NULL) return root;
        if(LeftOf(value, root))
            root->left = Delete(root->left, value, arrayID, arrayIDlength);
        else if(RightOf(value, root))
            root->right = Delete(root->right, value, arrayID, arrayIDlength);
        else{
            if(root->left == NULL){
                node_DanhSachTheDocGia* newRoot = root->right;
                Free(root);
                return newRoot;
            }
            if(root->right == NULL){
                node_DanhSachTheDocGia* newRoot = root->left;
                Free(root);
                return newRoot;
            }
            root->data = LeftMostValue(root->right);
            root->right = Delete(root->right, root->data, arrayID, arrayIDlength);
        }
        removeIDarray(value.maThe, arrayID, arrayIDlength);
        return root;
    }

    ModeDocGia mode;
    void LNR(node_DanhSachTheDocGia* &node, TheDocGia *nodes[MAX_RANGE], int n){
        if (node == NULL)   return;
        LNR(node->left, nodes, n);
        nodes[n++] = &node->data;
        LNR(node->right, nodes, n);
    }

    void getAllDocGia(node_DanhSachTheDocGia* &docGia, TheDocGia *nodes[MAX_RANGE], int n){
        n = 0;
        LNR(docGia, nodes, n);
        mode = MODE_MA_THE;
    }

    int compareDG(TheDocGia *a, TheDocGia *b){
        if (mode == MODE_MA_THE)
            return a->maThe - b->maThe;
        else if (mode == MODE_TEN)
            if (a->ten == b->ten){
                if (a->ho == b->ho)  return 0;
                else if (a->ho > b->ho) return 1;
                else    return -1;
            }
            else{
                if (a->ten == b->ten)    return 0;
                else if (a->ten > b->ten)   return 1;
                else    return -1;
            }
            return 0;
    }

    void Partition(int low, int high, TheDocGia *nodes[MAX_RANGE]){
        int i = low, j = high;
        TheDocGia *pivot = nodes[(low + high) / 2];
        TheDocGia *temp;
        
        do{
            while (compareDG(nodes[i], pivot) < 0) i++;
            while (compareDG(nodes[j], pivot) > 0) j--;
            if (i <= j){
                temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
                i++; j--;
            }
        } while (i <= j);

        if (low < j)    Partition(low, j, nodes);
        if (high > i)   Partition(i, high, nodes);
    }

    void SortMaTheDocGia(TheDocGia *nodes[MAX_RANGE], int n){
        if (mode != MODE_MA_THE && n > 0){
            mode = MODE_MA_THE;
            Partition(0, n-1, nodes);
        }
    }

    void SortTenDocGia(TheDocGia *nodes[MAX_RANGE], int n){
        if (mode != MODE_TEN && n > 0){
            mode = MODE_TEN;
            Partition(0, n-1, nodes);
        }
    }
}


// Đầu sách

namespace dau_sach{
    // Danh mục sách  
    void checkMaSach(DanhMucSach &dms, int arrayID[], int &arrayIDlength){
        bool isContinune = true;
        while(isContinune){
            if(arrayIDlength == 0){
                arrayIDlength++;
                arrayID[0] = dms.maSach;
                isContinune = false;
            }
            else{
                for (int i = 0; i < arrayIDlength; i++)
                {
                    if(dms.maSach == arrayID[i]){
                        dms.maSach = randomInt(MIN_RANGE, MAX_RANGE);
                        break;
                    }
                    if(i == arrayIDlength - 1 && dms.maSach != arrayID[i]){
                        isContinune = false;
                        arrayID[i+1] = dms.maSach;
                        arrayIDlength++;
                        isContinune = false;
                        break;
                    }
                }
            }
            continue;
        }
    }
    DanhMucSach *CreateDMS(TrangThaiSach trangthai, string viatri, int arrayID[], int &length){
        DanhMucSach* temp = new DanhMucSach;
        temp->maSach = randomInt(MIN_RANGE, MAX_RANGE);
        temp->trangThaiSach = trangthai;
        temp->viaTri = viatri;
        checkMaSach(*temp, arrayID, length);
        return temp;
    }
    
    node_DanhMucSach* AddToListBook(DanhMucSach* &dms, node_DanhMucSach *&llist){
        node_DanhMucSach* newllist = new node_DanhMucSach;
        newllist->dms = *dms;
        newllist->next = NULL;
        if(llist == NULL){
            // checkMaSach(*dms, arrayID, length);
            llist = newllist;
            return newllist;
        }
        // else if(llist != NULL && llist->next == NULL){
        //     llist->next = newllist;
        //     return newllist;
        // }
        else{
                AddToListBook(dms, llist->next);
            // checkMaSach(*dms, arrayID, length);
        }
    }
    
    DauSach* SearchDauSach(string tenSach, node_DauSach* listSach){
        for (int i = 0; i < listSach->size; i++)
        {
            if(listSach->node[i]->tenSach == tenSach) return listSach->node[i];
        }
        return NULL;
    }
    
    // Đầu sách
    DauSach Create(int ISBN, string tensach, int sotrang, string tacgia, int namxuatban, string theloai, node_DanhMucSach* danhMucSach){
        DauSach temp;
        temp.ISBN = ISBN;
        temp.tenSach = tensach;
        temp.soTrang = sotrang;
        temp.tacGia = tacgia;
        temp.namXuatBan = namxuatban;
        temp.theLoai = theloai;
        temp.dms = danhMucSach;
        
        return temp;
    }
    
    bool isNull(node_DauSach list){
        if(list.size = 0) return true;
        else return false;
    }
    bool isFull(node_DauSach list){
        if(list.size = MAX_DAU_SACH) return true;
        else return false;
    }
    
    enum status {
        SUCCESS,
        FAILED
    };
    status AddBook(DauSach* data, node_DauSach* &list){
        if(list->size == 0){
            list->size = 1;
            list->node[0] = data;
            return SUCCESS;
        }
        else{
            list->node[list->size] = data;
            list->size++;
            return SUCCESS;
        }
    }
//     void sortTheLoai(DauSach *data, string theloai){
//     for(i=1; i<MAX_DAU_SACH; i++)
//     {
//         for(j=1; j<MAX_DAU_SACH; j++)
//         {
//             if(strcmp(data[j-1], data[j])>0)
//             {
//                 strcpy(theloai, data[j-1]);
//                 strcpy(data[j-1], data[j]);
//                 strcpy(data[j], theloai);
//             }
//         }
//     }
// }
// void sortTenSach(DauSach *data, string tensach){
//     for(i=1; i<MAX_DAU_SACH; i++)
//     {
//         for(j=1; j<MAX_DAU_SACH; j++)
//         {
//             if(strcmp(data[j-1], data[j])>0)
//             {
//                 strcpy(tensach, data[j-1]);
//                 strcpy(data[j-1], data[j]);
//                 strcpy(data[j], tensach);
//             }
//         }
//     }
// }
}

namespace danh_sach_muon_tra{
    void MuonSach(node_DanhSachMuonTra* &dsmt, node_DanhSachTheDocGia* &nguoiMuon, int maSach, int ngay, int thang, int nam){
        if(nguoiMuon->data.trangThaiThe == HOAT_DONG && nguoiMuon->data.luotMuon > 0){
            DanhSachMuonTra data;
            data.IDnguoimuon = nguoiMuon->data.maThe;
            data.ngayMuon.day = ngay;
            data.ngayMuon.month = thang;
            data.ngayMuon.year = nam;
            data.trangThaiMuonTra = DANG_MUON;
            nguoiMuon->data.luotMuon--;
            if(dsmt == NULL)dsmt->data = data;
            else MuonSach(dsmt->next, nguoiMuon, maSach, ngay, thang, nam);
        }
        else if(nguoiMuon->data.trangThaiThe == BI_KHOA){
            cout << "ERROR:: The nay da bi khoa, vui long mo khoa the, ma the: " << nguoiMuon->data.maThe<<endl;
        }
        else if(nguoiMuon->data.luotMuon < 1){
            cout << "ERROR:: Nguoi dung da het luot muon! " <<endl;
        }
        else{
            cout << "ERROR:: Loi khong xac dinh!"<<endl;
        }
    }
    int countLeapYear(Date d){
        int years = d.year;
        if (d.month <= 2)
            years--;
        return years/4 - years/100 + years/400;
    }
    int getDateDifference(Date borrow, Date pay){
        long int n1 = borrow.year * 365 + borrow.day;
        for (int i = 0; i < borrow.month - 1; i++){
            n1 += dateOfMonth[i];
        }
        n1 += countLeapYear(borrow);
        long int n2 = pay.year * 365 + pay.day;
        for (int i = 0; i < pay.month - 1; i++){
            n2 += dateOfMonth[i];
        }
        n2 += countLeapYear(pay);
        return (n2 - n1);
    }
    node_DanhSachMuonTra* listDanhSachMuon(node_DanhSachMuonTra *&dsmt, int ngay, int thang, int nam, node_DanhSachTheDocGia* &dstdg, int ArrayID[], int arrayIDlength){
        dsmt->data.ngayTra.day = ngay;
        dsmt->data.ngayTra.month = thang;
        dsmt->data.ngayTra.year = nam;
        dsmt->data.trangThaiMuonTra = DA_TRA;
        node_DanhSachTheDocGia* nguoiMuon = the_doc_gia::IDSearch(dstdg, dsmt->data.IDnguoimuon, ArrayID, arrayIDlength);
        nguoiMuon->data.luotMuon++;
        if(getDateDifference(dsmt->data.ngayMuon, dsmt->data.ngayTra) > 7){
            nguoiMuon->data.trangThaiThe = BI_KHOA;
        }
    }
}
