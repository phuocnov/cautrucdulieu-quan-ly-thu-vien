#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>

#include "model/model.h"
using namespace std;
int main(){
    std::cout << "CHUONG TRINH QUAN LY THU VIEN" << std::endl;
    
    fstream fileInput("data/dausach.txt");
    
    while (!fileInput.eof())
    {
        DauSach dauSach;
            DanhMucSach danhmuc;
            
            fileInput >> dauSach.ISBN;
            fileInput.ignore();
            getline(fileInput, dauSach.tenSach);
            fileInput >> dauSach.soTrang;
            fileInput.ignore();
            getline(fileInput, dauSach.tacGia);
            fileInput >>dauSach.namXuatBan;
            fileInput.ignore();
            getline(fileInput, dauSach.theLoai);
            fileInput >> danhmuc.maSach;
            fileInput.ignore();
            getline(fileInput, danhmuc.viaTri);
    }
    
    
    getch();
    return 0;
}