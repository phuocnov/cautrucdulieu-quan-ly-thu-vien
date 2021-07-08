#include "data/iofile.cpp"
#include "Scene/consolehandle.cpp"

bool checkString_nonum(string str){
    bool temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <='Z' || str[i] ==' ')temp = true;
        else {
            temp = false;
            break;
        }
    }
    return temp;
}

bool checkString_num(string str){
    bool temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <='Z' || str[i] ==' '|| str[i] >= '0' && str[i] <='9')
            temp = true;
        else {
            temp = false;
            break;
        }
    }
    return temp;
}

bool checkWord_nonum(string str){
    bool temp;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <='Z')  
            temp = true;
        else {
            temp = false;
            break;
        }
    }
    return temp;
}

bool check_tdg(string ho, string ten, string phai){
    bool check_ho = checkString_nonum(ho);
    
    bool check_ten = checkWord_nonum(ten);
    
    bool check_phai;
    if(phai == "nam" || phai == "nu") check_phai = true;
    else check_phai = false;
    
    if(check_ten && check_ho && check_phai){
        return true;
    }
    else{
        return false;
    }
}

bool check_book(int isbn, string tensach, int sotrang, string tacgia, int namxuatban, string theloai, string viatri){
    bool check_isbn = (isbn > 10000000000000 && isbn < 99999999999999);
    bool check_tensach = checkString_num(tensach);
    bool check_tacgia = checkString_nonum(tacgia);
    bool check_viatri = checkString_num(viatri);
    bool check_nxb = (namxuatban > 0 && namxuatban < 2022);
    gotoxy(20, 17);
    if(!check_isbn) {
        cout << "ISBN khong hop le, phai la so co 14 chu so" << endl;
    }
    if(!check_tensach){
        cout << "Ten sach khong hop le, a-z, A-Z, 0-9" << endl;
    }
    if(!check_tacgia){
        cout << "Ten tac gia khong hop le, a-z, A-Z" << endl;
    }
    if(!check_nxb){
        cout << "Nam xuat ban khong hop le, 0-2021" << endl;
    }
    if(!check_viatri){
        cout << "Via tri khong hop le, a-z, A-Z, 0-9" << endl;
    }
    cout << "Nhan phim bat ky de tiep tuc"<< endl;
    getchar();
}