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
                fileInput << root->data.trangThaiThe << '\n' << '\n';
                
                WriteTheDocGia(fileInput, root->left);
                WriteTheDocGia(fileInput, root->right);
            }
        }
    } 
}


int main(){
    node_DanhSachTheDocGia* root = NULL;
    int arrayID[100];
    int size = 0;
    fstream fileInput("tdg.txt");
    the_doc_gia::ReadArrayID(fileInput, arrayID, size);
    the_doc_gia::ReadTheDocGia(fileInput, root, size);
    the_doc_gia::PrintDSTDG(root);
    fileInput.close();
    return 0;
}