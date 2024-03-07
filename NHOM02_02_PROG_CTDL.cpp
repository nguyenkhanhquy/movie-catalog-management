#include <iostream>
#include <conio.h> //getch()
#include <iomanip> //setw()
#include <fstream> //file
#include <windows.h> //setTextColor() //maximizeWindow()

using namespace std;

struct PHIM{
	string TenPhim;
	string TheLoai;
	string TenDaoDien;
	string TenDVNamChinh;
	string TenDVNuChinh;
	int NamSX;
	string HangSX;
	int SoGiai;
};

struct GIAI{
	string TenGiai;
	GIAI *pointer_giai;
};

struct LIST{
	PHIM data;	
	LIST *pointer;
	GIAI *pointer_giai;
};

//Menu
void inThongTinSinhVien();
void inMenu();
void goiMenu();

//Them Phim
void nhapThongTinPhim(PHIM *x);
void themPhimMoi(LIST **L); //1.

//In Thong Tin Theo Yeu Cau
void nhapTheLoai_InThongTinPhim(LIST *L); //2.
void nhapTenDVNamChinh_InThongTinPhim(LIST *L); //3.
void nhapTenDaoDien_InThongTinPhim(LIST *L); //4.
void nhapTenDaoDienVaNamSX_InThongTinPhim(LIST *L); //5.
void nhapTenPhim_InTenDaoDien(LIST *L); //7.
void nhapTenPhim_InTenDienVienChinh(LIST *L); //8.

//Bang Thong Tin
void inDongTieuDe();
void inDongGiua();
void inDongCuoi();
void inThongTinPhim(LIST *L, int STT);
void inBangThongTin(LIST *L);

//Giai Phong Danh Sach
void giaiPhongDSPhim(LIST **L);
void giaiPhongDSGiaiThuong(GIAI **G);

//Giai Thuong
void themGiaiThuongChoPhim(LIST **L); //6.
void nhapGiaiThuong(GIAI *G);
void xuatDSGiaiThuong(GIAI *G);
void nhapTenPhim_InGiaiThuong(LIST *L); //9.

//File
void luuFile(LIST *L); //11.
void moFile(LIST **L); //12.

//Chuyen String Sang Int
int chuyenStringSangInt(string s);

//Kiem Tra So Hop Le
bool kiemTraSoHopLe(string s);

//Set Text Color
void setTextColor(int x); //x la ma mau

//Resize Console
void maximizeWindow();

//Sap Xep Va In Cac Ten Phim Theo Thu Tu Tang Dan Cua Ten Phim
int timSoLuongPhim(LIST *L);
void themTenPhimVaoMang(LIST *L, string s[]);
void sapXepMangChuoiTangDan(string s[], int n);
void inTenPhimCoSapXepTangDan(LIST *L); //10.

//Main
int main()
{
	maximizeWindow();//Phong to cua so Console
	goiMenu();
	return 0;
}

//Menu
void inThongTinSinhVien()
{
	cout<<"[-] NHOM02_02_PROG_CTDL\n";
	cout<<"[-] K21 - HCMUTE\n";
	cout<<"[-] SINH VIEN NHOM 02\n";
	cout<<"\t[+] 30 - NGUYEN KHANH QUY\n";
	cout<<"\t[+] 21 - VO CHI KHUONG\n";
	cout<<"\t[+] 12 - NGUYEN HONG THONG DIEP\n\n";
}

void inMenu()
{
	setTextColor(2);//
	
	cout<<setw(84)<<left<<" "; //Do rong 84 ky tu, canh trai tu " " o dau
	cout<<"[#] QUAN LI DANH MUC CAC BO PHIM VIDEO [#]\n\n";
	
	cout<<setfill('='); //Set fill bang ky tu '='
	cout<<setw(102)<<"="; //Fill 102 ky tu bat dau tu "="
	cout<<" MENU ";
	cout<<setw(102)<<"="<<endl<<endl;
	cout<<setfill(' '); //Set fill bang ky tu ' ' nhu ban dau
	
	setTextColor(7);//
	
	cout<<setw(82)<<left<<" "<<"[1] THEM THONG TIN PHIM MOI VAO DANH SACH PHIM\n\n";
	cout<<setw(82)<<left<<" "<<"[2] TIM THONG TIN PHIM THEO THE LOAI\n\n";
	cout<<setw(82)<<left<<" "<<"[3] TIM THONG TIN PHIM THEO TEN DIEN VIEN NAM CHINH\n\n";
	cout<<setw(82)<<left<<" "<<"[4] TIM THONG TIN PHIM THEO TEN DAO DIEN\n\n";
	cout<<setw(82)<<left<<" "<<"[5] TIM THONG TIN PHIM THEO TEN DAO DIEN VA NAM SAN XUAT\n\n";
	cout<<setw(82)<<left<<" "<<"[6] THEM GIAI THUONG CHO PHIM\n\n";
	cout<<setw(82)<<left<<" "<<"[7] TIM TEN DAO DIEN THEO TEN PHIM\n\n";
	cout<<setw(82)<<left<<" "<<"[8] TIM TEN DIEN VIEN CHINH THEO TEN PHIM\n\n";
	cout<<setw(82)<<left<<" "<<"[9] TIM DANH SACH GIAI THUONG THEO TEN PHIM\n\n";
	cout<<setw(82)<<left<<" "<<"[t] IN DANH SACH TEN PHIM THEO THU TU TANG DAN\n\n";
	cout<<setw(82)<<left<<" "<<"[l] LUU FILE\n\n";
	cout<<setw(82)<<left<<" "<<"[m] MO FILE\n\n";
	cout<<setw(82)<<left<<" "<<"[i] IN DANH SACH CAC BO PHIM #\n\n";
	cout<<setw(82)<<left<<" "<<"[f] GIAI PHONG DANH SACH PHIM #\n\n";
	cout<<setw(82)<<left<<" "<<"[0] THOAT! *\n\n";
	
	setTextColor(2);//
	cout<<setfill('='); //Set fill bang ky tu '='
	cout<<setw(210)<<"="; //Fill 102 ky tu bat dau tu "="
	cout<<setfill(' ')<<endl; //Set fill bang ky tu ' ' nhu ban dau
	setTextColor(7);//	
	
	cout<<endl<<setw(82)<<left<<" "<<"[*] Nhan phim tuong ung -> ";
}

void goiMenu()
{
	LIST *dx;
	dx = NULL; //Khoi tao danh sach
	char chon;
	
	do
	{
		inThongTinSinhVien();
		inMenu();
		chon = getch();
		switch(chon){
			case '1':
				themPhimMoi(&dx);
				break;
			case '2':
				nhapTheLoai_InThongTinPhim(dx);
				break;
			case '3':
				nhapTenDVNamChinh_InThongTinPhim(dx);
				break;
			case '4':
				nhapTenDaoDien_InThongTinPhim(dx);
				break;
			case '5':
				nhapTenDaoDienVaNamSX_InThongTinPhim(dx);
				break;
			case '6':
				themGiaiThuongChoPhim(&dx);
				break;
			case '7':
				nhapTenPhim_InTenDaoDien(dx);
				break;
			case '8':
				nhapTenPhim_InTenDienVienChinh(dx);
				break;
			case '9':
				nhapTenPhim_InGiaiThuong(dx);
				break;
			case 't':
				inTenPhimCoSapXepTangDan(dx);
				break;
			case 'l':
				luuFile(dx);
				break;
			case 'm':
				moFile(&dx);
				break;
			case 'i':
				inBangThongTin(dx);
				break;
			case 'f':
				giaiPhongDSPhim(&dx);
				break;
			case '0':
				break;
			default:
				cout<<"Khong hop le ...\n\n";
				cout<<setw(82)<<left<<" "<<"[*] Nhan phim bat ky de thu lai -> ";
				getch();
		}
		system("cls");
	} 
	while (chon != '0');
	
	cout<<"Da thoat khoi chuong trinh !!!";//
}

//Them Phim
void nhapThongTinPhim(PHIM *x)
{
	char chon;
	bool check;
	string s;
	cout<<"Nhap thong tin phim ...\n\n";
	
	do
	{
		cout<<"[+] Nhap ten phim: ";
		getline(cin, (*x).TenPhim);	
		if ((*x).TenPhim == "") 
			cout<<"[+] Ten phim khong duoc de trong !!!\n";
	}
	while ((*x).TenPhim == "");
	
    cout<<"\n[+] Nhap the loai (nhan so tuong ung): \n";
    cout<<"\t   [1] Hinh su\n";
    cout<<"\t   [2] Tinh cam\n";
    cout<<"\t   [3] Hai\n";
    cout<<"\t-> ";
    while (true)
    {
    	chon = getch();
    	switch(chon){
	    	case '1':
	    		(*x).TheLoai = "Hinh su";
	    		break;
	    	case '2':
	    		(*x).TheLoai = "Tinh cam";
	    		break;
	    	case '3':
	    		(*x).TheLoai = "Hai";
	    		break;
	    	default:
	    		cout<<"Khong hop le ...\n";
	    		cout<<"\t-> ";
		}
		if (chon == '1' || chon == '2' || chon == '3')
		{
			cout<<"["<<chon<<"] "<<(*x).TheLoai<<endl;
			break;
		}
	}
    
    cout<<endl;
    do
	{
		cout<<"[+] Nhap ten dao dien: ";
		getline(cin, (*x).TenDaoDien);	
		if ((*x).TenDaoDien == "") 
			cout<<"[+] Ten dao dien khong duoc de trong !!!\n";
	}
	while ((*x).TenDaoDien == "");
	
	cout<<endl;
	do
	{
		cout<<"[+] Nhap ten dien vien nam chinh: ";
		getline(cin, (*x).TenDVNamChinh);	
		if ((*x).TenDVNamChinh == "") 
			cout<<"[+] Ten dien vien nam chinh khong duoc de trong !!!\n";
	}
	while ((*x).TenDVNamChinh == "");
   
   	cout<<endl;
	do
	{
		cout<<"[+] Nhap ten dien vien nu chinh: ";
		getline(cin, (*x).TenDVNuChinh);	
		if ((*x).TenDVNuChinh == "") 
			cout<<"[+] Ten dien vien nu chinh khong duoc de trong !!!\n";
	}
	while ((*x).TenDVNuChinh == "");
    
    cout<<endl;
    do
	{
		cout<<"[+] Nhap nam san xuat: ";
		getline(cin, s);	
		check = kiemTraSoHopLe(s);
		if (check == false)
			cout<<"[+] Nam san xuat phai la so va khong duoc de trong !!!\n";	
	}
	while (check == false);
	(*x).NamSX = chuyenStringSangInt(s);
    
    cout<<endl;
	do
	{
		cout<<"[+] Nhap hang san xuat: ";
		getline(cin, (*x).HangSX);	
		if ((*x).HangSX == "") 
			cout<<"[+] Hang san xuat khong duoc de trong !!!\n";
	}
	while((*x).HangSX == "");
	
	cout<<endl;
}

void themPhimMoi(LIST **L) //1.
{
	LIST *p;
	PHIM x;
	char chon;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] THEM THONG TIN PHIM MOI VAO DANH SACH PHIM ... \n\n";
	setTextColor(7);//
	cout<<"[-] Nhan 1 de them phim hoac nhan phim bat ky de ve menu -> ";
	chon = getch();
	while (chon == '1')
	{
		nhapThongTinPhim(&x);
		//
		p = new LIST;
		if (p == NULL)
		{
			cout<<"Loi cap phat vung nho !!!";
			exit(0);
		}
		//
		p->data = x;
		p->pointer = *L;
		//
		p->data.SoGiai = 0;
		p->pointer_giai = NULL;
		//
		*L = p;
		cout<<"[-] Nhan 1 de tiep tuc them phim hoac nhan phim bat ky de ve menu -> ";
		chon = getch();
	}
}

//In Thong Tin Theo Yeu Cau
void nhapTheLoai_InThongTinPhim(LIST *L) //2.
{
	LIST *p;
	char chon;
	string s;
	int count=0;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM THONG TIN PHIM THEO THE LOAI ...\n\n";
	setTextColor(7);//
	//Nhap the loai
	cout<<"[-] Chon the loai (nhan so tuong ung): \n";
    cout<<"\t   [1] Hinh su\n";
    cout<<"\t   [2] Tinh cam\n";
    cout<<"\t   [3] Hai\n";
    cout<<"\t-> ";
    while (true)
    {
    	chon = getch();
    	switch(chon){
	    	case '1':
	    		s = "Hinh su";
	    		break;
	    	case '2':
	    		s = "Tinh cam";
	    		break;
	    	case '3':
	    		s = "Hai";
	    		break;
	    	default:
	    		cout<<"Khong hop le ...\n";
	    		cout<<"\t-> ";
		}
		if (chon == '1' || chon == '2' || chon == '3')
		{
			cout<<"["<<chon<<"] "<<s<<"\n\n";
			break;
		}
	}
	
	//In bang thong tin theo the loai da nhap
	p=L;
	inDongTieuDe();
	while (p != NULL) 
	{
		if (s == p->data.TheLoai)
		{
			count++;
			if (count == 1)
				inThongTinPhim(p,count);
			else
			{
				inDongGiua();
				inThongTinPhim(p,count);
			}			
		}
		p = p->pointer;
	}	
	inDongCuoi();
	
	//In so luong bo phim cua the loai da nhap	
	cout<<"\n[-] Tim thay "<<count<<" bo phim the loai '"<<s<<"' ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapTenDVNamChinh_InThongTinPhim(LIST *L) //3.
{
	LIST *p;
	char chon;
	string s;
	int count=0;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM THONG TIN PHIM THEO TEN DIEN VIEN NAM CHINH ...\n\n";
	setTextColor(7);//
	//Nhap ten dien vien nam chinh
	do
	{
		cout<<"[-] Nhap ten dien vien nam chinh: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten dien vien nam chinh khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	//In bang thong tin theo ten dien vien nam da nhap
	p=L;
	inDongTieuDe();
	while (p != NULL) 
	{
		if (s == p->data.TenDVNamChinh)
		{
			count++;
			if (count == 1)
				inThongTinPhim(p,count);
			else
			{
				inDongGiua();
				inThongTinPhim(p,count);
			}			
		}
		p = p->pointer;
	}	
	inDongCuoi();
	
	//In so luong bo phim co dien vien nam da nhap dong
	cout<<"\n[-] Tim thay "<<count<<" bo phim co dien vien nam chinh '"<<s<<"' dong ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapTenDaoDien_InThongTinPhim(LIST *L) //4.
{
	LIST *p;
	char chon;
	string s;
	int count=0;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM THONG TIN PHIM THEO TEN DAO DIEN ...\n\n";
	setTextColor(7);//
	//Nhap ten dao dien
	do
	{
		cout<<"[-] Nhap ten dao dien: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten dao dien khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	//In bang thong tin theo ten dao dien da nhap
	p=L;
	inDongTieuDe();
	while (p != NULL) 
	{
		if (s == p->data.TenDaoDien)
		{
			count++;
			if (count == 1)
				inThongTinPhim(p,count);
			else
			{
				inDongGiua();
				inThongTinPhim(p,count);
			}			
		}
		p = p->pointer;
	}	
	inDongCuoi();
	
	//In so luong bo phim do dao dien da nhap dan dung
	cout<<"\n[-] Tim thay "<<count<<" bo phim do dao dien '"<<s<<"' dan dung ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapTenDaoDienVaNamSX_InThongTinPhim(LIST *L) //5.
{
	LIST *p;
	char chon;
	string s, nam;
	int count=0, namsx;
	bool check;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM THONG TIN PHIM THEO TEN DAO DIEN VA NAM SAN XUAT ...\n\n";
	setTextColor(7);//
	//Nhap ten dao dien
	do
	{
		cout<<"[-] Nhap ten dao dien: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten dao dien khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	//Nhap nam san xuat
	do
	{
		cout<<"[-] Nhap nam san xuat: ";
		getline(cin, nam);	
		check = kiemTraSoHopLe(nam);
		if (check == false)
			cout<<"[-] Nam san xuat phai la so va khong duoc de trong !!!\n";	
	}
	while (check == false);
	namsx = chuyenStringSangInt(nam);
	cout<<endl;
	
	//In bang thong tin theo ten dao dien da nhap
	p=L;
	inDongTieuDe();
	while (p != NULL) 
	{
		if (s == p->data.TenDaoDien && namsx == p->data.NamSX)
		{
			count++;
			if (count == 1)
				inThongTinPhim(p,count);
			else
			{
				inDongGiua();
				inThongTinPhim(p,count);
			}			
		}
		p = p->pointer;
	}	
	inDongCuoi();
	
	//In so luong bo phim do dao dien dan dung vao nam da nhap 
	cout<<"\n[-] Tim thay "<<count<<" bo phim do dao dien '"<<s<<"' dan dung vao nam '"<<namsx<<"'...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapTenPhim_InTenDaoDien(LIST *L) //7.
{
	LIST *p;
	string s;
	bool flag = false;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM TEN DAO DIEN THEO TEN PHIM ...\n\n";
	setTextColor(7);//
	//Nhap ten phim
	do
	{
		cout<<"[-] Nhap ten phim: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten phim khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	//In bang ten dao dien theo ten phim da nhap
	p = L;
	while (p != NULL)
	{
		if (s == p->data.TenPhim)
		{
			flag = true;
			cout<<"[-] Ten dao dien cua phim '"<<s<<"' la: "<<p->data.TenDaoDien<<endl;
			break;
		}
		p = p->pointer;
	}
	if (flag == false)
		cout<<"[-] Khong tim thay phim '"<<s<<"' ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapTenPhim_InTenDienVienChinh(LIST *L) //8.
{
	LIST *p;
	string s;
	bool flag = false;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM TEN DIEN VIEN CHINH THEO TEN PHIM ...\n\n";
	setTextColor(7);//
	//Nhap ten phim
	do
	{
		cout<<"[-] Nhap ten phim: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten phim khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	//In bang ten dien vien chinh theo ten phim da nhap
	p = L;
	while (p != NULL)
	{
		if (s == p->data.TenPhim)
		{
			flag = true;
			cout<<"[-] Ten dien vien nam chinh cua phim '"<<s<<"' la: "<<p->data.TenDVNamChinh<<endl;
			cout<<"\n[-] Ten dien vien nu chinh cua phim '"<<s<<"' la: "<<p->data.TenDVNuChinh<<endl;			
			break;
		}
		p = p->pointer;
	}
	if (flag == false)
		cout<<"[-] Khong tim thay phim '"<<s<<"' ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

//Bang Thong Tin
void inDongTieuDe()
{
	setTextColor(11);//
	cout<<setw(10)<<left<<"STT"<<setw(35)<<left<<"Ten phim"<<setw(25)<<left<<"The loai"<<setw(30)<<left<<"Ten dao dien";
	cout<<setw(30)<<left<<"Ten DV nam chinh"<<setw(25)<<left<<"Ten DV nu chinh";
	cout<<setw(25)<<left<<"Nam san xuat"<<setw(25)<<left<<"Hang san xuat"<<endl;

	cout<<setfill('=');
	cout<<setw(210)<<"="<<endl;
	cout<<setfill(' ');
	setTextColor(7);//
}

void inDongGiua()
{
	setTextColor(11);//
	cout<<setfill('-');
	cout<<setw(210)<<"-"<<endl;
	cout<<setfill(' ');
}

void inDongCuoi()
{
	setTextColor(11);//
	cout<<setfill('=');
	cout<<setw(210)<<"="<<endl;
	cout<<setfill(' ');
	setTextColor(7);//
}

void inThongTinPhim(LIST *L, int STT)
{
	LIST *p;
	p = L;
	
	setTextColor(10);//
	cout<<setw(10)<<left<<STT<<setw(35)<<left<<p->data.TenPhim<<setw(25)<<left<<p->data.TheLoai<<setw(30)<<left<<p->data.TenDaoDien;
	cout<<setw(30)<<left<<p->data.TenDVNamChinh<<setw(25)<<left<<p->data.TenDVNuChinh;
	cout<<setw(25)<<left<<p->data.NamSX<<setw(25)<<left<<p->data.HangSX<<endl;
}

void inBangThongTin(LIST *L)
{ 
	LIST *p;
	int count=0;
	p = L;
	
	system("cls");
	
	setTextColor(2);//
	cout<<"[*] IN DANH SACH CAC BO PHIM ...\n\n";
	setTextColor(7);//
	
	inDongTieuDe();
	while (p != NULL) 
	{
		count++;
		inThongTinPhim(p,count);
		if (p->pointer != NULL)
		{
			setTextColor(11);//
			inDongGiua();
		}
		p = p->pointer;
	}	
	inDongCuoi();
	
	setTextColor(7);//
	
	cout<<"\n[-] Danh sach hien co "<<count<<" bo phim ...\n";

	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

//Giai Phong Danh Sach
void giaiPhongDSPhim(LIST **L)
{ 
	system("cls");
	LIST *p, *q;
	p = *L;
	
	while (p != NULL) 
	{
		giaiPhongDSGiaiThuong(&(p->pointer_giai));
		q = p->pointer;
		delete p;
		p = q;
	}
	*L = NULL;
	
	setTextColor(2);//
	cout<<"[*] GIAI PHONG DANH SACH PHIM ...\n";
	setTextColor(7);//
	
	cout<<"\n[-] Da giai phong danh sach phim ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void giaiPhongDSGiaiThuong(GIAI **G)
{
	GIAI *p, *q;
	p = *G;
	
	while (p != NULL)
	{
		q = p->pointer_giai;
		delete p;
		p = q;
	}
	*G = NULL;
}

//Giai Thuong
void themGiaiThuongChoPhim(LIST **L) //6.
{
	GIAI *g;
    LIST *p, *q;
    p = *L;
    bool flag = false, check;
    string s, ns;
    int n, i;
    
    system("cls");
    setTextColor(2);//
    cout<<"[*] THEM GIAI THUONG CHO PHIM ...\n\n";
    setTextColor(7);//
    //Nhap ten phim can them giai thuong
	do
	{
		cout<<"[-] Nhap ten phim can them giai thuong: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten phim khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
    
    while (p != NULL)
    {
        if(s == p->data.TenPhim)
		{
			flag = true; 	
    		do
			{
				cout<<"[-] Nhap so luong giai can them: ";
    			getline(cin, ns);
    			cout<<endl;
				check = kiemTraSoHopLe(ns);
				if (check == false)
					cout<<"[-] So luong giai phai la so va khong duoc de trong !!!\n\n";	
			}
			while (check == false);
			n = chuyenStringSangInt(ns);	
    		
			for(i = 1; i <= n; i++)
			{
				g = new GIAI;
				nhapGiaiThuong(g);
				g->pointer_giai = p->pointer_giai;
				p->pointer_giai = g;
			}
			p->data.SoGiai += n;
			break;
    	}
		p = p->pointer;
	}
	if (flag == false)
		cout<<"[-] Khong tim thay phim ...\n\n";

	setTextColor(2);//
	cout<<"[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

void nhapGiaiThuong(GIAI *G)
{
	string s;
	do
	{
		cout<<"[-] Nhap ten giai thuong: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten giai thuong khong duoc de trong !!!\n";
	}
	while (s == "");
	G->TenGiai = s;
	cout<<endl;
}

void xuatDSGiaiThuong(GIAI *G)
{
	GIAI *p;
	p = G;
	
    while(p != NULL)
    {
        cout<<"    [+] "<<p->TenGiai<<endl;
        p = p->pointer_giai;
    }
}	

void nhapTenPhim_InGiaiThuong(LIST *L) //9.
{
	LIST *p;
	p = L;
	bool flag = false;
	string s;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] TIM DANH SACH GIAI THUONG THEO TEN PHIM ...\n\n";
	setTextColor(7);//
	//Nhap ten phim can tim giai thuong
	do
	{
		cout<<"[-] Nhap ten phim: ";
		getline(cin, s);	
		if (s == "") 
			cout<<"[-] Ten phim khong duoc de trong !!!\n";
	}
	while (s == "");
	cout<<endl;
	
	while (p != NULL)
	{
		if (s == p->data.TenPhim)
		{
			flag = true;
			cout<<"[-] Phim '"<<p->data.TenPhim<<"' hien co "<<p->data.SoGiai<<" giai thuong ...\n";
			if (p->data.SoGiai == 0)
				break;
			cout<<"\n[-] Danh sach giai thuong:\n";
			xuatDSGiaiThuong(p->pointer_giai);
			break;
		}
		p = p->pointer;
	}
	if (flag == false)
		cout<<"[-] Khong tim thay phim ...\n";
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}

//File
void luuFile(LIST *L) //11.
{
	char s[100];
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] LUU FILE ...\n\n";
	setTextColor(7);//
    cout<<"[-] Nhap duong dan (VD: D:\\DATACTDL\\phim.dat): ";
	cin>>s;
	
	cout<<"\n\t[+] Dang mo file -> "; 
	ofstream f(s, ios::out);
	if(!f.fail())
	{
		cout<<"Mo file thanh cong ...\n";
		cout<<"\n\t[+] Dang luu file -> ";
		LIST *p;
		p = L;
		while(p!=NULL)
		{
			f<<p->data.TenPhim<<","<<p->data.TheLoai<<","<<p->data.TenDaoDien<<","<<p->data.TenDVNamChinh<<",";
			f<<p->data.TenDVNuChinh<<","<<p->data.NamSX<<","<<p->data.HangSX<<","<<p->data.SoGiai;
			
			if(p->data.SoGiai > 0)
			{
				f<<":";
				GIAI *g;
				g = p->pointer_giai;
				while(g!=NULL)
				{
					f<<g->TenGiai;
					if (g->pointer_giai != NULL)
						f<<",";
					g = g->pointer_giai;
				}
			}
			
			if (p->pointer != NULL)
				f<<"\n";
				
			p = p->pointer;
		}	
		cout<<"Luu file thanh cong ...\n";
		cout<<"\n\t[+] Dang dong file -> ";
		f.close();
		cout<<"Dong file thanh cong ...\n";
	} 
	else
	{
		cout<<"Mo file khong thanh cong ...\n";	
	}

	setTextColor(2);//
    cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch(); 
	cin.ignore();
}

void moFile(LIST **L) //12.
{
	char s[100];
	string skip;
	int n, i;
	
	system("cls");
	setTextColor(2);//
	cout<<"[*] MO FILE ...\n\n";
	setTextColor(7);//
	cout<<"[-] Nhap duong dan (VD: D:\\DATACTDL\\phim.dat): ";
	cin>>s;
	
	cout<<"\n\t[+] Dang mo file -> ";
    ifstream f(s, ios::in);
	if(!f.fail())
	{
		cout<<"Mo file thanh cong ...\n";
		cout<<"\n\t[+] Dang doc file -> ";
		LIST *p, *q;
		p = new LIST;
		*L = p;
		while(!f.eof())
		{
			getline(f,p->data.TenPhim,',');
			getline(f,p->data.TheLoai,',');
			getline(f,p->data.TenDaoDien,',');
			getline(f,p->data.TenDVNamChinh,',');
			getline(f,p->data.TenDVNuChinh,',');
			
			f>>p->data.NamSX;
			getline(f,skip,',');

			getline(f,p->data.HangSX,',');		
			
			f>>p->data.SoGiai;	
			if(p->data.SoGiai > 0)
			{
				getline(f,skip,':');
				n = p->data.SoGiai;
				GIAI *g, *h;
				g = new GIAI;
				if (n == 1)
					getline(f,g->TenGiai,'\n');
				else
					getline(f,g->TenGiai,',');
				p->pointer_giai = g;
				for(i = 2; i <= n; i++)
				{
					h = new GIAI;
					if (i < n)
						getline(f,h->TenGiai,',');
					else
						getline(f,h->TenGiai,'\n');
        			g->pointer_giai = h;
        			g = h;
				}
				g->pointer_giai = NULL;
			}
			else
			{
				p->pointer_giai = NULL;
				getline(f,skip,'\n');
			}
			
			if (!f.eof())
			{
				q = new LIST;
				p->pointer = q;	
				p = q;
			}
			else//
				p->pointer = NULL;//
		}
		cout<<"Doc file thanh cong ...\n";
		
		//Xu ly khi mo file rong
		if (p->data.TenPhim == "")
		{
			delete p;
			*L = NULL;
		}
			
		cout<<"\n\t[+] Dang dong file -> ";	
		f.close();
		cout<<"Dong file thanh cong ...\n";
	} 
	else
	{
		cout<<"Mo file khong thanh cong ...\n";
	}

	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch(); 
	cin.ignore();
}

//Chuyen String Sang Int
int chuyenStringSangInt(string s)
{
	int i, len = s.length(), n = 0, temp;
	for (i=0; i<len; i++)
	{
		temp = s[i] - 48;
		n = n*10 + temp;
	}
	return n;
}

//Kiem Tra So Hop Le
bool kiemTraSoHopLe(string s)
{
	int i, len = s.length();
	if (len == 0)
		return false;
	for (i=0; i<len; i++)
		if (s[i] < '0' || s[i] > '9')
			return false;
	return true;
}

//Set Text Color
void setTextColor(int x) //x la ma mau
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//Resize Console
void maximizeWindow()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

//Sap Xep Va In Cac Ten Phim Theo Thu Tu Tang Dan Cua Ten Phim
int timSoLuongPhim(LIST *L)
{
	int n = 0;
	LIST *p;
	p = L;
	while (p!= NULL)
	{ 
		n++;
		p = p->pointer;
	}
	return n;
}

void themTenPhimVaoMang(LIST *L, string s[])
{
	int i = 0;
	LIST *p;
	p = L;
	while (p != NULL)
	{
		s[i] = p->data.TenPhim; 
		i++;
		p = p->pointer;
	}
}

void sapXepMangChuoiTangDan(string s[], int n)
{
	int i, j;
	string temp;
	for (i=0; i<(n-1); i++)
		for (j=i+1; j<n; j++)
			if (s[i] > s[j])
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
}

void inTenPhimCoSapXepTangDan(LIST *L) //10.
{
	system("cls");
	int n, i;
	string *s;
	LIST *p;
	
	p = L;
	n = timSoLuongPhim(L);
	s = new string[n];
	themTenPhimVaoMang(L, s);
	sapXepMangChuoiTangDan(s, n);
	
	setTextColor(2);//
	cout<<"[*] IN DANH SACH TEN PHIM THEO THU TU TANG DAN ...\n\n";
	setTextColor(7);//
	
	//In tieu de
	setTextColor(11);//
	cout<<setw(15)<<left<<"STT";
	cout<<"Ten phim"<<endl;
	
	//In dong dau
	cout<<setfill('=');
	cout<<setw(38)<<"="<<endl;
	cout<<setfill(' ');
	setTextColor(7);//
	for (i=0; i<n; i++)
	{
		if (i == 0)
		{
			cout<<setw(15)<<left<<i+1;
			cout<<s[i]<<endl;
		}
		else
		{
			//In dong giua
			setTextColor(11);//
			cout<<setfill('-');
			cout<<setw(38)<<"-"<<endl;
			cout<<setfill(' ');
			setTextColor(7);//
			
			cout<<setw(15)<<left<<i+1;
			cout<<s[i]<<endl;
		}
	}
	
	//In dong cuoi
	setTextColor(11);//
	cout<<setfill('=');
	cout<<setw(38)<<"="<<endl;
	cout<<setfill(' ');
	setTextColor(7);//
	
	cout<<"\n[-] Danh sach hien co "<<n<<" bo phim ...\n";
	
	delete[] s;// Giai phong mang s
	
	setTextColor(2);//
	cout<<"\n[*] Nhan phim bat ky de tro ve menu -> ";
	setTextColor(7);//

	getch();
}
