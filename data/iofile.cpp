#include <iostream>
#include <string>
#include <fstream>

#include "../model/model.h"


using namespace std;

namespace the_doc_gia{
    void PrintDSTDG(node_DanhSachTheDocGia* root){
        if(root != NULL){
            cout << root->data.maThe << "--" << root->data.ho << "--" << root->data.ten << "--" << root->data.phai << "--" << root->data.trangThaiThe << endl;
            
            PrintDSTDG(root->left);
            PrintDSTDG(root->right);
        }
    }

    void ReadArrayID(fstream& fileInput, int arrayID[], int& size){
        if(fileInput.fail()) cout << "ERROR:: Khong the mo File, vui long kiem tra lai!!" << endl;
        else {
            fileInput >> size;
            for (int i = 0; i < size; i++)
            {
                fileInput >> arrayID[i];
            }
            
        }
    }

    void ReadTheDocGia(fstream& fileInput, node_DanhSachTheDocGia* &root, int size){
        if(fileInput.fail()) cout << "ERROR:: Khong the mo File, vui long kiem tra lai!!" << endl;
        else {
            for (int i = 0; i < size; i++)
            {
                TheDocGia tdg;
                fileInput >> tdg.maThe;
                fileInput.ignore();
                getline(fileInput, tdg.ho);
                fileInput >> tdg.ten;
                fileInput >> tdg.phai;
                int temp;
                fileInput >> temp;
                if(temp == 1) tdg.trangThaiThe = HOAT_DONG;
                else if(temp == 0) tdg.trangThaiThe = BI_KHOA;
                fileInput >> tdg.luotMuon;
                
                the_doc_gia::Insert(root, tdg);
            }
            
        }
    }

    void WriteArray(fstream& fileInput, int arrayID[], int size){
        fileInput << size << endl;
        for (int i = 0; i < size; i++)
        {
            fileInput << arrayID[i] << '\t';
        }
        fileInput << '\n' << endl;
    }

    void WriteTheDocGia(fstream& fileInput, node_DanhSachTheDocGia* root){
        if(fileInput.fail()) cout << "ERROR:: Khong the mo File, vui long kiem tra lai!!" << endl;
        else{
            if(root != NULL){
                fileInput << root->data.maThe << '\n';
                fileInput << root->data.ho << '\n';
                fileInput << root->data.ten << '\n';
                fileInput << root->data.phai << '\n';
                fileInput << root->data.trangThaiThe << '\n';
                fileInput << root->data.luotMuon << '\n'  << '\n';
                
                WriteTheDocGia(fileInput, root->left);
                WriteTheDocGia(fileInput, root->right);
            }
        }
    }
}

namespace dau_sach{
void ReadArrayID(fstream& fileInput, int arrayID[], int &size){
    if(fileInput.fail()) cout << "ERROR:: Khong the mo File, vui long kiem tra lai!!" << endl;
    else {
        fileInput >> size;
        for (int i = 0; i < size; i++)
        {
            fileInput >> arrayID[i];
        }
        fileInput.ignore();
    }
}
void ReadBookData(fstream& fileInput, node_DanhMucSach* &node_dms, node_DauSach* &node_dausach, int size, int arrayDMS[]){
    if(fileInput.fail()) cout << "ERROR:: Khong the mo File, vui long kiem tra lai!!" << endl;
    else{
        for (int i = 0; i < size; i++){
            string isbn, tensach, tacgia, theloai, viatri;
            int sotrang, namxuatban, masach;
            fileInput.ignore();
            fileInput >> isbn;
            fileInput.ignore();
            getline(fileInput, tensach);
            fileInput >> sotrang;
            fileInput.ignore();
            getline(fileInput, tacgia);
            fileInput >>namxuatban;
            fileInput.ignore();
            getline(fileInput, theloai);
            fileInput >> masach;
            fileInput.ignore();
            getline(fileInput,viatri);
            
            // DanhMucSach* dms = dau_sach::CreateDMS(CHO_MUON_DUOC, viatri, arrayDMS, size);
            DanhMucSach* dms = new DanhMucSach;
            dms->maSach = masach;
            dms->trangThaiSach = CHO_MUON_DUOC;
            dms->viaTri = viatri;
            node_DanhMucSach* bind = dau_sach::AddToListBook(dms, node_dms);
            DauSach* dausach = new DauSach;
            *dausach = dau_sach::Create(isbn, tensach, sotrang, tacgia, namxuatban, theloai, bind);
            dau_sach::AddBook(dausach, node_dausach);
            
            
            // dau_sach::AddToListBook(danhmuc, node_dms);
            // dau_sach::AddBook(&dauSach, node_dausach);
        }
    }
}
void WriteArrayDMS(fstream& fileInput, int arrayID[], int size){
    fileInput << size << endl;
    for (int i = 0; i < size; i++)
    {
        fileInput << arrayID[i] << '\t';
    }
    fileInput << '\n' << endl;
}

void WriteBookData(fstream& fileInput, node_DauSach* node_dausach){
    for (int i = 0; i < node_dausach->size; i++)
    {
        fileInput << node_dausach->node[i]->ISBN << endl;
        fileInput << node_dausach->node[i]->tenSach << endl;
        fileInput << node_dausach->node[i]->soTrang << endl;
        fileInput << node_dausach->node[i]->tacGia << endl;
        fileInput << node_dausach->node[i]->namXuatBan << endl;
        fileInput << node_dausach->node[i]->theLoai << endl;
        fileInput << node_dausach->node[i]->dms->dms.maSach << endl;
        fileInput << node_dausach->node[i]->dms->dms.viaTri << endl;
        fileInput << endl;
    }
    
}
}

// int main(){
//     // node_DanhSachTheDocGia* root = NULL;
//     // int arrayID[100];
//     // int size = 0;
//     // fstream fileInput("tdg.txt");
//     // the_doc_gia::ReadArrayID(fileInput, arrayID, size);
//     // the_doc_gia::ReadTheDocGia(fileInput, root, size);
//     // the_doc_gia::PrintDSTDG(root);
//     // fileInput.close();
    
//     node_DanhMucSach* node_dms = NULL;
//     node_DauSach* node_dausach = new node_DauSach;
    
//     int arrayDMS[100];
//     int arraysize = 0;
    
//     // Create DMS and add to it
    
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     DanhMucSach* dms = dau_sach::CreateDMS(CHO_MUON_DUOC, "tu 3 ke 2", arrayDMS, arraysize);
//     //     node_DanhMucSach* bindtobook = dau_sach::AddToListBook(dms, node_dms);
//     //     DauSach* dausach = new DauSach;
//     //     *dausach = dau_sach::Create("12412", "tenSach", 500, "tacGia", 2012, "theLoai", bindtobook);
//     //     dau_sach::AddBook(dausach, node_dausach);
//     // }
    
//     fstream fileInput("dausach.txt");
    
//     // dau_sach::WriteArrayDMS(fileInput, arrayDMS, arraysize);
//     // dau_sach::WriteBookData(fileInput, node_dausach);
    
//     dau_sach::ReadArrayID(fileInput, arrayDMS, arraysize);
//     dau_sach::ReadBookData(fileInput, node_dms, node_dausach, arraysize, arrayDMS);
    
//     fileInput.close();
//     return 0;
// }