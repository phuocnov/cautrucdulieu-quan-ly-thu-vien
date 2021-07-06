#include "data/iofile.cpp"

bool check_tdg(string ho, string ten, string phai){
    bool check_ho = true;
    for(int i = 0; i < ho.length(); i++){
        if(ho[i] >= 'a' && ho[i] <= 'z' || ho[i] >= 'A' && ho[i] <='Z' || ho[i] ==' ') check_ho =true;
        else {
            check_ho = false;
            break;
        }
    }
    
    bool check_ten = true;
    for(int i = 0; i < ten.length(); i++){
        if(ho[i] >= 'a' && ho[i] <= 'z' || ho[i] >= 'A' && ho[i] <='Z') check_ho =true;
        else {
            check_ten = false;
            break;
        }
    }
    
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