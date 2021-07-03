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
    dau_sach::CreateAndAddBook(node_dms, node_dausach, arrayDMS, arraysize);
    dau_sach::CreateAndAddBook(node_dms, node_dausach, arrayDMS, arraysize);
    dau_sach::CreateAndAddBook(node_dms, node_dausach, arrayDMS, arraysize);
    cout << "cac";
}