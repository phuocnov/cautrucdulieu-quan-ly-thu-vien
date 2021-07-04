#include <iostream>
#include <conio.h>
#include <string.h>
// inlude model
#include "model.h"

#define MAX_ARRAY 100

using namespace std;

// void CreateAndAddBook(node_DanhMucSach* &node_dms, node_DauSach* &node_dausach, int arrayDMS[], int &size){
//         int ISBN;
//         string tenSach;
//         int soTrang;
//         string tacGia;
//         int namXuatBan;
//         string theLoai;
        
//         cin >> ISBN;
//         cin.ignore();
//         getline(cin ,tenSach);
//         cin >> soTrang;
//         cin.ignore();
//         getline(cin, tacGia);
//         cin >> namXuatBan;
//         cin.ignore();
//         getline(cin, theLoai);
        
//         TrangThaiSach trangThaiSach = CHO_MUON_DUOC;
//         string viaTri;
//         cin.ignore();
//         getline(cin, viaTri);
        
//         DanhMucSach dms = dau_sach::CreateDMS(trangThaiSach, viaTri, arrayDMS, size);
//         dau_sach::AddToListBook(dms, node_dms, arrayDMS, size);
//         DauSach dausach = dau_sach::Create(ISBN, tenSach, soTrang, tacGia, namXuatBan, theLoai, &dms);
//         dau_sach::AddBook(&dausach, 1, node_dausach);
//     }

int main(){
    // Create dms, only 1 
    node_DanhMucSach* node_dms = NULL;
    node_DauSach* node_dausach = NULL;
    
    int arrayDMS[100];
    int arraysize = 0;
    // Create DMS and add to it
    for (int i = 0; i < 10; i++)
    {
        DanhMucSach* dms = dau_sach::CreateDMS(CHO_MUON_DUOC, "tu 3 ke 2", arrayDMS, arraysize);
        node_DanhMucSach* bindtobook = dau_sach::AddToListBook(dms, node_dms, arrayDMS, arraysize);
        DauSach* dausach = new DauSach;
        *dausach = dau_sach::Create(12412, "tenSach", 500, "tacGia", 2012, "theLoai", bindtobook);
        dau_sach::AddBook(dausach, node_dausach);
    }
    
    cout << "cac";
}