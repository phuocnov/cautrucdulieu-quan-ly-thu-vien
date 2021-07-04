#include <iostream>
#include <conio.h>
#include <string.h>
// inlude model
#include "model.h"

#define MAX_ARRAY 100

using namespace std;

void PrintNode(node_DanhSachTheDocGia* node){
    if(node){
        cout << node->data.maThe << "-- " << node->data.ho << "--" << node->data.ten << "--" << node->data.phai << "--" << node->data.trangThaiThe << endl;
    }
}

void PrintDSTDG(node_DanhSachTheDocGia* root){
    if(root != NULL){
        cout << root->data.maThe << "-- " << root->data.ho << "--" << root->data.ten << "--" << root->data.phai << "--" << root->data.trangThaiThe << endl;
        
        PrintDSTDG(root->left);
        PrintDSTDG(root->right);
    }else{
        // cout << "vao``" << endl;
    }
}
void PrintTDG(TheDocGia data){
    cout << "--PRINT THE DOC GIA--" << endl;
    cout << data.maThe << "-- " << data.ho << "--" <<data.ten << "--" << data.phai << "--" << data.trangThaiThe << endl;
}

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    cout << "TEST CASE 1:: TAO, XUAT THE DOC GIA" << endl;
    // CODE Here
    node_DanhSachTheDocGia* root_dstdg = NULL;
    
    // Mảng chứa ID của độc giả để so sánh
    int arrayIDlength = 0;
    int arrayID[MAX_ARRAY];
    
    // Khởi tạo 10 độc giả
    for (size_t i = 0; i < 10; i++)
    {
        TheDocGia newTDG = the_doc_gia::Create("Nguyen Huu", "Phuoc", "Nam", arrayID, arrayIDlength);
        the_doc_gia::Insert(root_dstdg, newTDG);
    }
    PrintDSTDG(root_dstdg);
    
    //  Xuất mảng ID
    PrintArray(arrayID, arrayIDlength);
    
    // biến test
    int ID = 0;
    node_DanhSachTheDocGia* searchResult = NULL;
    
    cout << "TEST CASE 2:: SEARCH BY ID" << endl;
    cout << "Nhap MA the: ";
    cin >> ID;
    searchResult = the_doc_gia::IDSearch(root_dstdg, ID, arrayID, arrayIDlength);
    cout << "KET QUA" << endl;
    PrintNode(searchResult);
    
    
    cout << "TEST CASE 3:: DELETE BY ID" << endl;
    cout << "Nhap MA the: ";
    cin >> ID;
    searchResult = the_doc_gia::IDSearch(root_dstdg, ID, arrayID, arrayIDlength);
    
    if(searchResult != NULL) {
        the_doc_gia::Delete(root_dstdg, searchResult->data, arrayID, arrayIDlength);
        cout << "Danh sach sau khi xoa"<< endl;
        PrintDSTDG(root_dstdg);
        PrintArray(arrayID, arrayIDlength);    
    }
    
    // cout << "TEST CASE 4:: EDIT PROFILE" << endl;
    // cout << "Nhap MA the: ";
    // cin >> ID;
    // searchResult = IDSearch(root_dstdg, ID);
    // Edit(searchResult, "Nguyen Hoai", "An", "Nu");
    // PrintDSTDG(root_dstdg);
    
    
    // PrintDSTDG(root_dstdg);
    the_doc_gia::Free(root_dstdg);
    // Pause screen
    getch();
    return 0;
}   