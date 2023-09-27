#include<iostream>


using namespace std;

#define MAX 50

#define TRUE 1

#define FALSE  0

int A[MAX][MAX], n,u;

void Init(void){

 cin>>n;

//  cout<<" So dinh cua do thi n = "<<n<<endl;

 // nhap ma tran lien ke.

 for(int i=1; i<=n;i++){

  for(int j=1; j<=n;j++){

   cin>>A[i][j];

  }
 }
  cin >> u;
}

int Kiemtra(){

 int s, d;

 d=0;

 for(int i=1; i<=n;i++){

  s=0;

  for(int j=1; j<=n;j++)

   s+=A[i][j];//đếm các bậc của các đỉnh của đồ thị

  if(s%2) d++;

 }

 if(d>0) return(FALSE); //Nếu có 1 đỉnh bậc lẻ thì đồ thị không có chu trình Euler.

 return(TRUE); //Nếu tất cả các đỉnh của đồ thị là chắn thì đồ thị có thể có chu trình Euler.

}

void Tim(){

 int v, x, top, dCE;

 int stack[MAX], CE[MAX];

 top=1;

 stack[top]=u;//thêm đỉnh u vào stack.

 dCE=0;

 do {

  v = stack[top];//lấy đỉnh trên cùng của stack.

  x=1;

  while (x<=n && A[v][x]==0) //tìm trong danh sách những đỉnh kề với đỉnh v.

   x++;

  if (x>n) { //lấy ra khỏi stack.

   dCE++;

   CE[dCE]=v;//lưu đỉnh v vào mảng kết quả duyệt CE.

   top--;

  }

  else { //đỉnh x là đỉnh kề với đỉnh v.

   top++;

   stack[top]=x;

   A[v][x]=0;

   A[x][v]=0;

  }

 } while(top!=0);

//  cout<<" Co chu trinh Euler:";

 for(x=dCE; x>0; x--)

  cout<<CE[x]<<" "; //in ra kết quả dưới dạng char.

}

int main(){

 Init();

 if(Kiemtra())

  Tim();

 else printf("\n Khong co chu trinh Euler");


}