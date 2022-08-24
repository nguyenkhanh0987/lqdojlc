//ThangNN - chuong trinh nguon tao tu luong vao ra chuan
#include<bits/stdc++.h>
#include <windows.h>
#include <direct.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
ofstream fo;
ifstream fi;
char Name_file[] = "loco";
char exe_file[100] = "";

char inp_file[100] = "";
char out_file[100] = "";
string folder = "TestXX"; //XX will change value during running test

void Rename_file(int test) {
   folder[4] = test / 10 + 48; //tao ten cuoi cho folder tu 00-->99
   folder[5] = test % 10 + 48;
   mkdir(&folder[0]);
   string output_path = folder + "\\" + inp_file;
   CopyFile(inp_file, &output_path[0], false);
   output_path = folder + "\\" + out_file;
   CopyFile(out_file, &output_path[0], false);
}
void Make_file_name() {
   strcpy(exe_file, Name_file);
   strcpy(inp_file, Name_file);
   strcpy(out_file, Name_file);
   strcat(exe_file, ".exe");
   strcat(inp_file, ".inp");
   strcat(out_file, ".out");
}
int dem = 1; //test dau tien la dem=1
void make_sub1(int cnt, int minn, int maxn) {  //tao bo test cho sub có cnt test, gioi han trong tu LOW den HIGH
   for(int i = 0; i < cnt; i++, dem++) {
      fo.open(inp_file);  //tao test
      int step = (maxn - minn) / cnt;
      int n = minn + i * step;
      fo << n << " " << 1 + rand() % (n / 2) << endl;
      for(int i = 1; i <= n; i++)
         fo << 1 + rd() % n << " ";
      fo.close();
      //tao file ket qua
      freopen(inp_file, "r", stdin);
      freopen(out_file, "w", stdout);
      system(exe_file);
      //Xoa file
      Rename_file(dem); //Luu lai file ket qua
   }
}

int main() {
   srand(time(NULL));
   Make_file_name();
   make_sub1(24, 5, 1000);
   make_sub1(16, 10000, 500000);
   DeleteFile(inp_file);
   DeleteFile(out_file);
   return 0;
}
