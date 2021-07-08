#include <limits>
#include <cstddef>
#include <iostream>
#include <string.h>
#include <fstream>

#include "errorcheck.cpp"
using namespace std;

#define MAX_TDG 100
#define MAX_DAUSACH 100

enum Scene{
    MAIN_MENU,
    DOC_GIA,
    MUON_TRA,
    DOC_GIA_PERSONAL,
    DOC_GIA_PERSONAL_ADD,
    DOC_GIA_PERSONAL_REMOVE,
    DOC_GIA_PERSONAL_ADJUST,
    DOC_GIA_LIST,
    DOC_GIA_LIST_PRINT,
    DAU_SACH,
    DAU_SACH_ADD,
    DAU_SACH_LIST
};

// Main Program
    Scene scene = MAIN_MENU;
    int optionSize = 4;
    int colorArray[10] = {1, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int option = 0; 
    bool isRunning = true;
    
void resetcolorarray(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        arr[i] = 7;
    }
    arr[0] = 1;
}

// Navigation
void nav_mainmenu(){
    scene = MAIN_MENU;
    optionSize = 4;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}

void nav_docgia(){
    scene = DOC_GIA;
    optionSize = 3;
    option = 0;                    
    resetcolorarray(colorArray, optionSize);
}

void nav_docgia_personal(){
    scene = DOC_GIA_PERSONAL;
    optionSize = 4;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}

void nav_docgia_personal_remove(){
    scene = DOC_GIA_PERSONAL_REMOVE;
    option =0;
    resetcolorarray(colorArray, optionSize);
    optionSize = 5;
}

void nav_docgia_personal_add(){
    scene = DOC_GIA_PERSONAL_ADD;
    option =0;
    resetcolorarray(colorArray, optionSize);
    optionSize = 5;
}
void nav_docgia_personal_adjust(){
    scene = DOC_GIA_PERSONAL_ADJUST;
    option =0;
    resetcolorarray(colorArray, optionSize);
    optionSize = 6;
}

void nav_docgia_list(){
    scene = DOC_GIA_LIST;
    optionSize = 4;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}

void nav_docgia_list_print(){
    scene = DOC_GIA_LIST_PRINT;
    optionSize = 4;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}

void nav_dausach(){
    scene = DAU_SACH;
    optionSize = 5;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}
void nav_dausach_add(){
    scene = DAU_SACH_ADD;
    optionSize = 9;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}
void nav_dausach_list(){
    scene = DAU_SACH_LIST;
    optionSize = 1;
    option = 0;
    resetcolorarray(colorArray, optionSize);
}
void PrintDocGiaList(node_DanhSachTheDocGia* root){
    if(root != NULL){
        cout << root->data.maThe << "-- " << root->data.ho << "--" << root->data.ten << "--" << root->data.phai << "--" << root->data.trangThaiThe << endl;
        PrintDocGiaList(root->left);
        PrintDocGiaList(root->right);
    }
}

int main(){
    // Console setup
    SetWindowSize(160, 90);
    // Data initialization
    node_DanhSachTheDocGia* node_dstdg = NULL;
    int array_tdg[MAX_TDG];
    int arraytdg_size = 0;
    string ho, ten, phai;
    int IDsearch;
    node_DanhSachTheDocGia* search_result = NULL;

    node_DauSach* node_dausach = new node_DauSach;
    node_DanhMucSach* node_dms = new node_DanhMucSach;
    int arrayDMS[MAX_DAUSACH];
    int arraydms_size = 0;
    int isbn = 0, sotrang = 0, namxuatban = 0;
    string tensach, tacgia, theloai, viatri;

    
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
            SetColor(6); gotoxy(30, 3); cout << "Chinh sua the doc gia";
            
            if(search_result != NULL){
                SetColor(colorArray[0]); gotoxy(20,7);  cout << "Ma the";
                SetColor(colorArray[1]); gotoxy(20,8);  cout << "Ho";
                SetColor(colorArray[2]); gotoxy(20,9);  cout << "Ten";
                SetColor(colorArray[3]); gotoxy(20,10);  cout << "Phai";
                SetColor(colorArray[4]); gotoxy(20,11);  cout << "Luu";
                SetColor(colorArray[5]); gotoxy(20,12);  cout << "Thoat";
                
                SetColor(colorArray[0]); gotoxy(30,7);  cout << search_result->data.maThe;
                SetColor(colorArray[1]); gotoxy(30,8);  cout << search_result->data.ho;
                SetColor(colorArray[2]); gotoxy(30,9);  cout << search_result->data.ten;
                SetColor(colorArray[3]); gotoxy(30,10);  cout << search_result->data.phai;
            }
            else{
                SetColor(6); gotoxy(20, 4); cout << "Nhap ID doc gia"; cin >> IDsearch;
                search_result = the_doc_gia::IDSearch(node_dstdg, IDsearch, array_tdg, arraytdg_size);
                if(search_result == NULL){
                    SetColor(7);
                    gotoxy(20, 5);
                    cout << "ID khong ton tai, nhan phim bat ky de tiep tuc";
                    getchar();
                    nav_docgia_personal();
                }
                continue;
            }
        break;
        case DOC_GIA_PERSONAL_REMOVE:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Xoa sua the doc gia";
             if(search_result != NULL){
                SetColor(7); gotoxy(20,7);  cout << "Ma the";
                SetColor(7); gotoxy(20,8);  cout << "Ho";
                SetColor(7); gotoxy(20,9);  cout << "Ten";
                SetColor(7); gotoxy(20,10);  cout << "Phai";
                SetColor(colorArray[0]); gotoxy(20,11);  cout << "Xoa";
                SetColor(colorArray[1]); gotoxy(20,12);  cout << "Huy";
                
                SetColor(7); gotoxy(30,7);  cout << search_result->data.maThe;
                SetColor(7); gotoxy(30,8);  cout << search_result->data.ho;
                SetColor(7); gotoxy(30,9);  cout << search_result->data.ten;
                SetColor(7); gotoxy(30,10);  cout << search_result->data.phai;
            }
            else{
                SetColor(6); gotoxy(20, 4); cout << "Nhap ID doc gia"; cin >> IDsearch;
                search_result = the_doc_gia::IDSearch(node_dstdg, IDsearch, array_tdg, arraytdg_size);
                if(search_result == NULL){
                    SetColor(7);
                    gotoxy(20, 5);
                    cout << "ID khong ton tai, nhan phim bat ky de tiep tuc";
                    getchar();
                    nav_docgia_personal();
                }
                continue;
            }
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
        
        case DAU_SACH:
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Quan ly dau sach";
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "1. Them sach";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "2. Xuat ra danh sach";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "3. Nhap danh sach the doc gia tu file";
            SetColor(colorArray[3]); gotoxy(20,10);  cout << "4. Xuat danh sach the doc gia tu file";
            SetColor(colorArray[4]); gotoxy(20,11);  cout << "5. Quay tro lai";
        break;
        case DAU_SACH_ADD: 
            clrscr();
            SetColor(6); gotoxy(30, 3); cout << "Them dau sach";
            
            SetColor(colorArray[0]); gotoxy(20,7);  cout << "ISBN:  ";
            SetColor(colorArray[1]); gotoxy(20,8);  cout << "Ten sach:  ";
            SetColor(colorArray[2]); gotoxy(20,9);  cout << "So trang   :";
            SetColor(colorArray[3]); gotoxy(20,10);  cout << "Tac gia:";
            SetColor(colorArray[4]); gotoxy(20,11);  cout << "Nam xuat ban: ";
            SetColor(colorArray[5]); gotoxy(20,12);  cout << "The loai:";
            SetColor(colorArray[6]); gotoxy(20,13);  cout << "Via tri:  ";
            SetColor(colorArray[7]); gotoxy(20,14);  cout << "Luu";
            SetColor(colorArray[8]); gotoxy(20,15);  cout << "Thoat";

            // Value input
            SetColor(colorArray[0]); gotoxy(40,7);  cout << isbn;
            SetColor(colorArray[1]); gotoxy(40,8);  cout << tensach;
            SetColor(colorArray[2]); gotoxy(40,9);  cout << sotrang;
            SetColor(colorArray[3]); gotoxy(40,10);  cout << tacgia;
            SetColor(colorArray[4]); gotoxy(40,11);  cout << namxuatban;
            SetColor(colorArray[5]); gotoxy(40,12);  cout << theloai;
            SetColor(colorArray[6]); gotoxy(40,13);  cout << viatri;
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
                    nav_docgia();
                }
                if(option == 1)nav_dausach();
                if(option == 2)scene = MUON_TRA;
                if(option == 3) return 0;
                break;
            case DOC_GIA:
                if(option == 0){
                    nav_docgia_personal();
                }
                if(option == 1){
                    nav_docgia_list();
                }
                if(option == 2){
                    nav_mainmenu();
                }
                break;
            case DOC_GIA_PERSONAL:
                if(option == 0){
                    nav_docgia_personal_add();
                }
                if(option == 1){
                    scene = DOC_GIA_PERSONAL_REMOVE;
                }
                if(option == 2){
                    nav_docgia_personal_adjust();
                }
                if(option == 3){
                    nav_docgia();
                }
                break;
            case DOC_GIA_PERSONAL_ADD:
                if(option == 0){
                    SetColor(2);
                    gotoxy(20, 12);
                    cout << "Nhap ho:";
                    fflush(stdin);
                    getline(cin, ho);
                }
                if(option == 1){
                    SetColor(2);
                    gotoxy(20, 12);
                    cout << "Nhap ten:";
                    fflush(stdin);
                    cin >> ten;
                }
                if(option ==2){
                    gotoxy(20, 13); cout <<"LUU Y:: Phai nhap 1 trong 2 nam hoac nu !!";
                    fflush(stdin);
                    SetColor(2);gotoxy(20, 12);cout << "Nhap gioi tinh:";cin >> phai;
                }
                if(option == 3){
                    SetColor(2);
                    gotoxy(20, 14);
                    cout << "Tao moi the doc gia??? y/n";
                    char ans;
                    ans = getchar();
                    if(ans == 'y'){
                        if(check_tdg(ho, ten, phai)){
                            TheDocGia newTDG = the_doc_gia::Create(ho, ten, phai, array_tdg, arraytdg_size);
                            the_doc_gia::Insert(node_dstdg, newTDG);
                            gotoxy(20, 14);
                            cout << "Thanh cong, bam phim bat ky de tiep tuc";
                            getchar();
                        }
                        else{
                            gotoxy(20, 14);
                            cout << "That bai, vui long kiem tra lai du lieu nhap, bam phim bat ky de tiep tuc";
                            getchar();
                        }
                    }
                    else if(ans == 'n'){
                        ho = "";
                        ten = "";
                        phai = "";
                    }
                }
                if(option == 4){
                    nav_docgia_personal();
                }
            break;
            
            case DOC_GIA_PERSONAL_ADJUST:
                if(search_result && option == 1){
                    SetColor(colorArray[0]); gotoxy(20,12);  cout << "Nhap thay doi: ";
                    fflush(stdin);
                    getline(cin, ho);
                }
                if(search_result && option == 2){
                    SetColor(colorArray[0]); gotoxy(20,12);  cout << "Nhap thay doi: ";
                    cin >> ten;
                }
                if(search_result && option == 3){
                    SetColor(colorArray[0]); gotoxy(20,12);  cout << "Nhap thay doi: ";
                    cin >> phai;
                }
                if(search_result && option == 4){
                    SetColor(colorArray[0]); gotoxy(20,12);  cout << "Xac nhan thay doi? y/n";
                    char ans = getchar();
                    if(ans=='y'){
                        the_doc_gia::Edit(search_result, ho, ten, phai);
                        SetColor(colorArray[0]); gotoxy(20,13);  cout << "Thanh cong";
                        search_result = NULL;
                        ho="";
                        ten="";
                        phai="";
                        nav_docgia_personal();
                    }
                }
                if(search_result && option == 5){
                    nav_docgia_personal();
                }
            break;
            
            case DOC_GIA_PERSONAL_REMOVE:
                if(option == 0 && search_result != NULL){
                    the_doc_gia::Delete(node_dstdg, search_result->data, array_tdg, arraytdg_size);
                    gotoxy(20, 12); cout << "Thanh cong! nhan phim bat ki de tiep tuc";
                    nav_docgia();
                    getchar();
                }
                if(option == 1) nav_docgia_personal();
            break;
                
            case DOC_GIA_LIST:
                if(option == 0){
                    nav_docgia_list_print();
                }
                if(option == 1){
                    fstream file_tdg("data/tdg.txt");
                    the_doc_gia::ReadArrayID(file_tdg, array_tdg, arraytdg_size);
                    the_doc_gia::ReadTheDocGia(file_tdg, node_dstdg, arraytdg_size);
                    gotoxy(20, 12); cout << "Thanh cong! nhan phim bat ki de tiep tuc";
                    getchar();
                }
                if(option == 2){
                    fstream file_tdg("data/tdg.txt");
                    the_doc_gia::WriteArray(file_tdg, array_tdg, arraytdg_size);
                    the_doc_gia::WriteTheDocGia(file_tdg, node_dstdg);
                    gotoxy(20, 12); cout << "Thanh cong! nhan phim bat ki de tiep tuc";
                    getchar();
                }
                if(option == 3){
                    nav_docgia();
                }
            break;
            case DOC_GIA_LIST_PRINT:
                nav_docgia_list();
            break;
            case DAU_SACH:
                if(option == 0){
                    nav_dausach_add();
                }
                if(option == 1){
                    nav_dausach_list();
                }
                if(option == 2){
                    fstream file_dausach("data/dausach.txt");
                    dau_sach::ReadArrayID(file_dausach, arrayDMS, arraydms_size);
                    dau_sach::ReadBookData(file_dausach, node_dms, node_dausach, arraydms_size, arrayDMS);
                    SetColor(3);gotoxy(20, 17);cout << "Nhap thanh cong!! Nhan phim bat ky de tiep tuc";
                    getchar();
                }
                if(option == 3){
                    fstream file_dausach("data/dausach.txt");
                    dau_sach::WriteArrayDMS(file_dausach, arrayDMS, arraydms_size);
                    dau_sach::WriteBookData(file_dausach, node_dausach);
                    SetColor(3);gotoxy(20, 17);cout << "Nhap thanh cong!! Nhan phim bat ky de tiep tuc";
                    getchar();
                }
                if(option == 4) nav_mainmenu();
            break;
            case DAU_SACH_ADD:
                if(option == 0){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap ISBN: ";fflush(stdin); cin >>isbn;
                }
                if(option == 1){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap ten sach: ";fflush(stdin); getline(cin,tensach);
                }
                if(option == 2){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap so trang: "; cin >> sotrang;
                }
                if(option == 3){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap tac gia "; fflush(stdin); getline(cin, tacgia);
                }
                if(option == 4){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap nam xuat ban "; cin >> namxuatban;
                }
                if(option == 5){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap the loai"; fflush(stdin); getline(cin, theloai);
                }
                if(option == 6){
                    SetColor(3);gotoxy(20, 17);cout << "Nhap via tri"; fflush(stdin); getline(cin,viatri);
                }
                if(option == 7){
                    if(check_book(isbn, tensach, sotrang, tacgia, namxuatban, theloai, viatri)){
                        DanhMucSach* dms = dau_sach::CreateDMS(CHO_MUON_DUOC, viatri, arrayDMS, arraydms_size);
                        node_DanhMucSach* bindtobook = dau_sach::AddToListBook(dms, node_dms);
                        DauSach* dausach = new DauSach;
                        *dausach = dau_sach::Create(isbn, tensach, sotrang, tacgia, namxuatban, theloai, bindtobook);
                        SetColor(3);gotoxy(20, 17);cout << "Thanh cong!!, nhan phim bat ki de tiep tuc";
                        getchar();
                        nav_dausach();
                    }
                }
                if(option == 8){
                    nav_dausach();
                }
            break;
            case DAU_SACH_LIST:{
                nav_dausach();
            }
            default:
                break;
            }
        }
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}