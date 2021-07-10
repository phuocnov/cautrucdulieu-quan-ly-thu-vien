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

bool checkString_num_only(string str){
    bool temp;
    if(str.length() != 14) return false;
    else{
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= '0' && str[i] <='9')
                temp = true;
            else {
                temp = false;
                break;
            }
        }
        return temp;
    }
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

bool check_book(string isbn, string tensach, int sotrang, string tacgia, int namxuatban, string theloai, string viatri){
    bool check_isbn = checkString_num_only(isbn);
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
    return (check_isbn && check_tensach && check_tacgia && check_viatri && check_nxb);
}

bool check_date(int d, int m, int y){
    bool check_d, check_m, check_y;
    if(y < 0){
        cout << "Nam phai la 1 so duong, lon hon 0" << endl;
        return false;
    }
    if(m < 1 && m > 12){
         cout << "Thang phai la 1 so nguyen tu 1-12" << endl;
         return false;
    }
    if(d < 1 && d > dateOfMonth[m]){
        cout << "Ngay phai trong khoang 1, " << dateOfMonth[m]<< endl;
        return false;
    }
    return true;
}