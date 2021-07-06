#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>

#include "errorcheck.cpp"
#include "Scene/consolehandle.cpp"
using namespace std;

#define MAX_TDG 100

enum Scene{
    MAIN_MENU,
    DOC_GIA,
    DAU_SACH,
    MUON_TRA,
    DOC_GIA_PERSONAL,
    DOC_GIA_PERSONAL_ADD,
    DOC_GIA_PERSONAL_REMOVE,
    DOC_GIA_PERSONAL_ADJUST,
    DOC_GIA_LIST,
    DOC_GIA_LIST_PRINT
};

void PrintDocGiaList(node_DanhSachTheDocGia* root){
    if(root != NULL){
        // gotoxy(10, 7); cout << "Ma the";
        // gotoxy(20, 7); cout << "Ho";
        // gotoxy(70, 7); cout << "Ten";
        // gotoxy(80, 7); cout << "Phai";
        // gotoxy(90, 7); cout << "Trang thai the";
        cout << root->data.maThe << "-- " << root->data.ho << "--" << root->data.ten << "--" << root->data.phai << "--" << root->data.trangThaiThe << endl;
        
        
        PrintDocGiaList(root->left);
        PrintDocGiaList(root->right);
    }else{
        // cout << "vao``" << endl;
    }
}

void resetcolorarray(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        arr[i] = 7;
    }
    arr[0] = 1;
}

int main(){
    // Console setup
    SetWindowSize(160, 90);
    // Data initialization
    // Doc gia
    node_DanhSachTheDocGia* node_dstdg = NULL;
    int array_tdg[MAX_TDG];
    int arraytdg_size = 0;
    string ho, ten, phai;
    fstream file_dausach("data/tdg.txt");
    
    
    node_DauSach* node_dausach = new node_DauSach;
    node_DanhMucSach* node_dms = new node_DanhMucSach;
    
    // Main Program
    Scene scene = MAIN_MENU;
    int optionSize = 4;
    int colorArray[10] = {1, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int option = 0; 
    bool isRunning = true;
    
    
    while(isRunning){
        switch (scene)
        {
        case MAIN_MENU:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Quan ly thu vien";
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "1) The Doc Gia";
		    SetColor(colorArray[1]); gotoxy(20,8);  cout << "2) Dau Sach";
		    SetColor(colorArray[2]); gotoxy(20,9);  cout << "3) Danh Sach Muon Tra";
		    SetColor(colorArray[3]); gotoxy(20,10); cout << "Thoat chuong trinh";
            break;
        case DOC_GIA:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Quan ly danh sach doc gia";
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "1. Them, xoa, sua the doc gia";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "2. In danh sach the doc gia";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "3. Quay tro lai";
            break;
        case DOC_GIA_PERSONAL:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Quan ly danh sach doc gia";
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "1. Them";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "2. Xoa";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "3. Sua";
            SetColor(colorArray[3]); gotoxy(20,10);  cout << "4. Quay tro lai";
            break;
        case DOC_GIA_PERSONAL_ADD:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Tao moi the doc gia";
            // Field
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "Ho";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "Ten";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "Phai";
            SetColor(colorArray[3]); gotoxy(20,10);  cout << "Luu";
            SetColor(colorArray[4]); gotoxy(20,11);  cout << "Thoat";
            
            // Value input
            SetColor(colorArray[0]); gotoxy(30,7);  cout << ho;
            SetColor(colorArray[1]); gotoxy(30,8);  cout << ten;
            SetColor(colorArray[2]); gotoxy(30,9);  cout << phai;
            break;
        case DOC_GIA_PERSONAL_ADJUST:
            clrscr();
            PrintDocGiaList(node_dstdg);
            break;
        case DOC_GIA_PERSONAL_REMOVE:
            clrscr();
            
            break;
        case DOC_GIA_LIST:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Quan ly danh sach doc gia";
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "1. Xuat ra danh sach the doc gia";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "2. Nhap danh sach the doc gia tu file";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "3. Xuat danh sach the doc gia tu file";
            SetColor(colorArray[3]); gotoxy(20,10);  cout << "4. Quay tro lai";
            break;
        case DOC_GIA_LIST_PRINT:
            clrscr();
            PrintDocGiaList(node_dstdg);
            break;
        default:
            break;
        }
        system("pause>nul");
        
        
        if(GetAsyncKeyState(VK_DOWN) && option < optionSize){
            option++;
            for(int i = 0; i < optionSize; i++) colorArray[i] = 7;
            colorArray[option] = 1;
            continue;     
            
		}
			
		if(GetAsyncKeyState(VK_UP) && option > 0){
            option--;
            for(int i = 0; i < optionSize; i++) colorArray[i] = 7;
            colorArray[option] = 1;
            continue;
		}
        
        if(GetAsyncKeyState(VK_RETURN)){
            // Main menu
            switch (scene)
            {
            case MAIN_MENU:
                if(option == 0){
                    scene = DOC_GIA;
                    optionSize = 3;
                    option = 0;                    
                    resetcolorarray(colorArray, optionSize);
                }
                if(option == 1)scene = DAU_SACH;
                if(option == 2)scene = MUON_TRA;
                if(option == 3) return 0;
                break;
            case DOC_GIA:
                if(option == 0){
                    scene = DOC_GIA_PERSONAL;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
                if(option == 1){
                    scene = DOC_GIA_LIST;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
                if(option == 2){
                    scene = MAIN_MENU;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
                break;
            case DOC_GIA_PERSONAL:
                if(option == 0){
                    scene = DOC_GIA_PERSONAL_ADD;
                    option =0;
                    resetcolorarray(colorArray, optionSize);
                    optionSize = 5;
                }
                if(option == 1){
                    scene = DOC_GIA_PERSONAL_ADJUST;
                }
                if(option == 2){
                    scene = DOC_GIA_PERSONAL_REMOVE;
                }
                if(option == 3){
                    scene = DOC_GIA;
                    optionSize = 3;
                    option = 0;                    
                    resetcolorarray(colorArray, optionSize);
                }
                break;
            case DOC_GIA_PERSONAL_ADD:
                if(option == 0){
                    SetColor(2);
                    gotoxy(20, 12);
                    cout << "Nhap ho:  ";
                    fflush(stdin);
                    getline(cin, ho);
                }
                if(option == 1){
                    SetColor(2);
                    gotoxy(20, 12);
                    cout << "Nhap ten:  ";
                    fflush(stdin);
                    cin >> ten;
                }
                if(option ==2){
                    gotoxy(20, 13); cout <<"LUU Y:: Phai nhap 1 trong 2 nam hoac nu !!";
                    SetColor(2);gotoxy(20, 12);cout << "Nhap gioi tinh:  ";cin >> phai;
                }
                if(option == 3){
                    SetColor(2);
                    gotoxy(20, 11);
                    cout << "Tao moi the doc gia??? y/n";
                    char ans;
                    ans = getch();
                    if(ans == 'y'){
                        if(check_tdg(ho, ten, phai)){
                            TheDocGia newTDG = the_doc_gia::Create(ho, ten, phai, array_tdg, arraytdg_size);
                            the_doc_gia::Insert(node_dstdg, newTDG);
                            gotoxy(20, 14);
                            cout << "Thanh cong, bam phim bat ky de tiep tuc";
                            getch();
                        }
                        else{
                            gotoxy(20, 14);
                            cout << "That bai, vui long kiem tra lai du lieu nhap, bam phim bat ky de tiep tuc";
                            getch();
                        }
                    }
                    else if(ans == 'n'){
                        ho = "";
                        ten = "";
                        phai = "";
                    }
                }
                if(option == 4){
                    scene = DOC_GIA_PERSONAL;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
            break;
                
            case DOC_GIA_LIST:
                if(option == 0){
                    scene = DOC_GIA_LIST_PRINT;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
                if(option == 1){
                    the_doc_gia::ReadArrayID(file_dausach, array_tdg, arraytdg_size);
                    the_doc_gia::ReadTheDocGia(file_dausach, node_dstdg, arraytdg_size);
                    gotoxy(20, 12); cout << "Thanh cong! nhan phim bat ki de tiep tuc";
                    getch();
                }
                if(option == 2){
                    
                }
                if(option == 3){
                    scene = DOC_GIA;
                    optionSize = 3;
                    option = 0;                    
                    resetcolorarray(colorArray, optionSize);
                }
            break;
            case DOC_GIA_LIST_PRINT:
                if(option == 0){
                    scene = DOC_GIA_LIST;
                    optionSize = 4;
                    option = 0;
                    resetcolorarray(colorArray, optionSize);
                }
            break;
            default:
                break;
            }
        }
    }
}