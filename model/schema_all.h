#include <string>
#include <ctime>

using namespace std;

#define MAX_DAU_SACH 100

// Danh mục sách, danh sách liên kết đơn

enum TrangThaiSach{
    CHO_MUON_DUOC,
    DA_DUOC_MUON,
    DA_THANH_LY
};

struct DanhMucSach{
    int maSach;
    TrangThaiSach trangThaiSach;
    string viaTri;
};

struct node_DanhMucSach{
  DanhMucSach dms;
  node_DanhMucSach* next; 
};

// Danh sách thẻ độc giả, cây nhị phân

enum TrangThaiThe{
  BI_KHOA,
  HOAT_DONG  
};

struct TheDocGia{
    int maThe;
    string ho;
    string ten;
    string phai;
    TrangThaiThe trangThaiThe;
};

struct node_DanhSachTheDocGia{
    TheDocGia data;
    node_DanhSachTheDocGia* left;
    node_DanhSachTheDocGia* right;
};

// Danh sách mượn trả, danh sách liên kết đơn
enum TrangThaiMuonTra{
    DANG_MUON,
    DA_TRA
};

struct DanhSachMuonTra{
    int maSach;
    tm ngayMuon;
    tm ngayTra;
    TrangThaiMuonTra trangThaiMuonTra;
};

struct node_DanhSachMuonTra{
    DanhSachMuonTra data;
    node_DanhSachMuonTra* next;
};

// Đầu sách, danh sách tuyến tính

struct DauSach{
    int ISBN;
    string tenSach;
    int soTrang;
    string tacGia;
    int namXuatBan;
    string theLoai;
    node_DanhMucSach* dms;
};

struct node_DauSach{
    int size;
    DauSach* node[MAX_DAU_SACH];
};