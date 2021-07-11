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

    // ModeDocGia mode;
    // void LNR(node_DanhSachTheDocGia* &node, TheDocGia *nodes[MAX_RANGE], int n){
    //     if (node == NULL)   return;
    //     LNR(node->left, nodes, n);
    //     nodes[n++] = &node->data;
    //     LNR(node->right, nodes, n);
    // }

    // void getAllDocGia(node_DanhSachTheDocGia* &docGia, TheDocGia *nodes[MAX_RANGE], int n){
    //     n = 0;
    //     LNR(docGia, nodes, n);
    //     mode = MODE_MA_THE;
    // }

    // int compareDG(TheDocGia *a, TheDocGia *b){
    //     if (mode == MODE_MA_THE)
    //         return a->maThe - b->maThe;
    //     else if (mode == MODE_TEN)
    //         if (a->ten == b->ten){
    //             if (a->ho == b->ho)  return 0;
    //             else if (a->ho > b->ho) return 1;
    //             else    return -1;
    //         }
    //         else{
    //             if (a->ten == b->ten)    return 0;
    //             else if (a->ten > b->ten)   return 1;
    //             else    return -1;
    //         }
    //         return 0;
    // }

    // void Partition(int low, int high, TheDocGia *nodes[MAX_RANGE]){
    //     int i = low, j = high;
    //     TheDocGia *pivot = nodes[(low + high) / 2];
    //     TheDocGia *temp;
        
    //     do{
    //         while (compareDG(nodes[i], pivot) < 0) i++;
    //         while (compareDG(nodes[j], pivot) > 0) j--;
    //         if (i <= j){
    //             temp = nodes[i];
    //             nodes[i] = nodes[j];
    //             nodes[j] = temp;
    //             i++; j--;
    //         }
    //     } while (i <= j);

    //     if (low < j)    Partition(low, j, nodes);
    //     if (high > i)   Partition(i, high, nodes);
    // }
    
    void exportTDGtolist(node_DanhSachTheDocGia* root, TheDocGia out[], int &count){
        if (root != NULL)
        {
            out[count] = root->data;
            count++;
            exportTDGtolist(root->left, out, count);
            exportTDGtolist(root->right, out, count);
        }
    }
    
    void swap_docgia(TheDocGia &a, TheDocGia &b){
        TheDocGia temp = a;
        a = b;
        b = temp;
    }
    
    void SortMaTheDocGia(TheDocGia nodes[], int n){
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++){
                if(nodes[i].maThe<nodes[j].maThe) swap_docgia(nodes[i], nodes[j]);
            }
        }
    }

    void SortTenDocGia(TheDocGia nodes[], int n){
        for (int i = 0; i < n; i++)
        {
            for(int j =0; j < n; j++){
                if(nodes[i].ten.compare(nodes[j].ten) < 0) swap_docgia(nodes[i], nodes[j]);
            }
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
    
    DauSach* SearchDauSach(int maSach, node_DauSach* listSach){
        for (int i = 0; i < listSach->size; i++)
        {
            if(listSach->node[i]->dms->dms.maSach == maSach) return listSach->node[i];
        }
        return NULL;
    }
    
    // Đầu sách
    DauSach Create(string ISBN, string tensach, int sotrang, string tacgia, int namxuatban, string theloai, node_DanhMucSach* danhMucSach){
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
    void swapDausach(DauSach &a, DauSach &b){
        DauSach temp = a;
        a = b;
        b = temp;
    }
    void sortDauSach(DauSach list[], int size){
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(list[i].theLoai < list[j].theLoai) swapDausach(list[i], list[j]);
            }
            
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(list[i].theLoai == list[j].theLoai && list[i].tenSach.compare(list[j].tenSach) < 0) swapDausach(list[i], list[j]);
            }
            
        }
    }
    
    
}

namespace danh_sach_muon_tra{
    void Add(node_DanhSachMuonTra* node, node_DanhSachMuonTra* &list){
        if(list == NULL){
            list = node;
        }
        else Add(node, list->next);
    }
    
    void MuonSach(node_DanhSachMuonTra* &dsmt, int &size, node_DanhSachTheDocGia* &nguoiMuon, int maSach, int ngay, int thang, int nam){
        if(nguoiMuon->data.trangThaiThe == HOAT_DONG && nguoiMuon->data.luotMuon > 0){
            DanhSachMuonTra data;
            data.IDnguoimuon = nguoiMuon->data.maThe;
            data.maSach = maSach;
            data.ngayMuon.day = ngay;
            data.ngayMuon.month = thang;
            data.ngayMuon.year = nam;
            data.trangThaiMuonTra = DANG_MUON;
            nguoiMuon->data.luotMuon--;
            if(dsmt == NULL){
                size++;
                dsmt = new node_DanhSachMuonTra;
                dsmt->data = data;
                dsmt->next = NULL;
            }
            else MuonSach(dsmt->next, size, nguoiMuon, maSach, ngay, thang, nam);
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
    node_DanhSachMuonTra* Findlist(int mathe, int masach, node_DanhSachMuonTra* list){
        if(list == NULL) return NULL;
        if(list->data.IDnguoimuon == mathe && list->data.maSach == masach) return list;
        else Findlist(mathe, masach, list->next);
    }
    node_DanhSachMuonTra* TraSach(node_DanhSachMuonTra *&dsmt, int ngay, int thang, int nam, node_DanhSachTheDocGia* &dstdg, int ArrayID[], int arrayIDlength){
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
    void print(node_DanhSachMuonTra* list){
        if (list != NULL)
        {
            cout << list->data.IDnguoimuon << "--" << list->data.maSach << "--" << list->data.ngayMuon.day << "/" << list->data.ngayMuon.month << "/" << list->data.ngayMuon.year;
            if(list->data.trangThaiMuonTra == DA_TRA)
                cout << "Ngay tra: " <<  list->data.ngayTra.day << "/" << list->data.ngayTra.month << "/" << list->data.ngayTra.year;
            cout << endl;
            print(list->next);
        }
    }
    void print_person(int ID, node_DanhSachMuonTra* list){
        if (list != NULL && list->data.IDnguoimuon == ID && list->data.trangThaiMuonTra == DANG_MUON)
        {
            cout << list->data.IDnguoimuon << "--" << list->data.maSach << "--" << list->data.ngayMuon.day << "/" << list->data.ngayMuon.month << "/" << list->data.ngayMuon.year;
            if(list->data.trangThaiMuonTra == DA_TRA)
                cout << "Ngay tra: " <<  list->data.ngayTra.day << "/" << list->data.ngayTra.month << "/" << list->data.ngayTra.year;
            cout << endl;
        }
        if(list->next != NULL) print_person(ID, list->next);
    }
    
    struct listmasach{
        int arr_mathe[100];
        int size = 0;
    };
    listmasach export_masach(listmasach result, node_DanhSachMuonTra* list){
        while (list != NULL)
        {
            result.arr_mathe[result.size] =  list->data.maSach;
            result.size++;
            export_masach(result, list->next);
        }
    }
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    void top_10(node_DanhSachMuonTra* list, node_DauSach* node_ds){
        int rs[100][2];
        int size = 0;
        
        while(list != NULL){
            if(size == 0){
                rs[0][0] = list->data.maSach;
                rs[0][1] = 1;
                size++;
            }
            else{
                for (int i = 0; i < size; i++)
                {
                    if(list->data.maSach == rs[i][0]) rs[i][1]++;
                    if(i == size - 1 && list->data.maSach != rs[i][0]){
                        rs[size][0] = list->data.maSach;
                        rs[size][1] = 1;
                        size++;
                    }
                }
                
            }
            list = list->next;
        }
        
        for(int i = 0; i < size; i++){
            for (int j = 0; j < size; j++)
            {
                if(rs[i][1] > rs[j][1]){
                    swap(rs[i][0], rs[j][0]);
                    swap(rs[i][1], rs[j][1]);
                }
            }
            
        }
        if(size <= 10){
            for(int i = 0; i < size; i++){
                DauSach* emp = dau_sach::SearchDauSach(rs[i][0], node_ds);
                cout << emp->tenSach << "--" << emp->tacGia << "--" << "luot muon: "<< rs[i][1] << endl;
            }
        }
        else{
            for(int i = 0; i < 10; i++){
                DauSach* emp = dau_sach::SearchDauSach(rs[i][0], node_ds);
                cout << emp->tenSach << "--" << emp->tacGia << "--" << "luot muon: "<< rs[i][1] << endl;
            }
        }
    }
}
