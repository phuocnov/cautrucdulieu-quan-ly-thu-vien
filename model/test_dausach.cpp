#include <iostream>
#include <conio.h>
#include <string.h>
// inlude model
#include "model.h"

#define MAX_ARRAY 100

using namespace std;

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
        node_DanhMucSach* bindtobook = dau_sach::AddToListBook(dms, node_dms);
        DauSach* dausach = new DauSach;
        *dausach = dau_sach::Create("12412", "tenSach", 500, "tacGia", 2012, "theLoai", bindtobook);
        dau_sach::AddBook(dausach, node_dausach);
    }
    
    return 0;
}