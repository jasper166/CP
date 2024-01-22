#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll  MODULO = 1e9+7;
ll inv_MODULO = ((MODULO + 1) / 2LL );

/*
Konichiwa
Konichiwa
Ara ~~ ara

Bob no taisuki - Shinobu Kocho
    * * * * *
  *          *
 *         *
*         *        I love SHINOBU <3 <3 <3
 *         *
  *          *
    * * * * *
*/

/*
_________________________


    Author : Bob15324

_________________________
*/


/*
okay i'm hoping that somebody pray for me
I'm praying that somebody hope for me
I'm staying where nobody 'posed to be
p-p-posted
being a wreak of emotions
ready to go whenever just let me know
the road is long so put the pedal into the floor
the enemy's on my trail
my energy unavailble
Imma tell em hasta luego
they wanna plot on my trot to the top
I've been outta shape thinking out the box I'm an astronaut
i balsted off the planet rock to cause catastrophe and it matters
more because i had it not
had i thought about wreaking havoc on an opposition
kinda shocking they wanted static
with precision i'm automatic quarterback
i ain't talking sacking pack itpack it up i don't panic
who the badopt it doesn't matter cause we at ya throat
*/

// EVERYBODY WANT TO BE MY ENEMY

template<class X , class Y>
    bool Minimize(X & x , Y y)
    {
        if( x == -1|| (x >y && y >= 0 ) )
        {
            x = y;
            return true;
        }
        return false;
    }

template<class X , class Y>
    bool Maximize(X & x , Y y)
    {
        if( x < y)
        {
            x = y;
            return true;
        }
        return false;
    }
template<class X , class Y>
    void Add(X &x , Y y )
    {
        x += y;
        if(x >= MODULO)
        {
            x -= MODULO;
        }
    }
template<class X , class Y>
    void Sub(X &x ,Y y)
    {
        x -=  y;
        if(x < 0)
        {
            x += MODULO;
        }
    }

/* End of templates. Let's see what do we have here */
const int N = 1e6+1;
const int INF = 1e9+7;
int n , q , a[N];

struct node{
    int mini ;
    ll val = 0;
    node(){
        mini = -1;
        val = 0;
    }
}st[N  * 4];

void build(int l, int r, int id){
    if(l == r){
        st[id].mini = st[id].val = a[l];
        return ;
    }
    int mid = (l+r) / 2;
    build(l , mid , id * 2);
    build(mid + 1, r , id * 2 + 1);

    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    st[id].mini = min(st[id * 2].mini , st[id * 2 + 1].mini);
}

bool update(int l, int r, int id, int u, int v, int val, int target){
    if(l > v || u > r || st[id].mini > target)
        return false; 
    
    if(l == r){
        st[id].mini = st[id].val = val;
        return true;
    }

    int mid =  (l+r) / 2;
    if(update(l , mid , id * 2 , u , v , val , target)){
        st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
        st[id].val = st[id * 2].val + st[id * 2 + 1].val;
        return true;
    }
    
    if(update(mid + 1, r , id * 2 + 1 , u  , v , val , target)){
       st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
       st[id].val = st[id * 2].val + st[id * 2 + 1].val;
       return true;
    }

    st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    return false;
}

int get_min(int l ,int r ,int id , int u ,int v){
    if(l > v || u > r)
    {
        return INF;
    }
    if(u <= l && r <= v)
    {
        return st[id].mini;
    }
    int mid = (l+r) / 2;
    return min(get_min(l , mid , id * 2 , u , v) , get_min(mid + 1 , r, id * 2 + 1 , u , v));
}

ll get(int l ,int r , int id , int u ,int v)
{
    if( l > v || u > r)
    {
        return 0;
    }
    if(u <= l && r <= v)
    {
        return st[id].val;
    }
    int mid = (l+r) / 2;
    return get(l , mid , id * 2 , u , v) + get(mid + 1 , r, id * 2 + 1 , u, v);
}

void Input()
{
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin  >> a[i];
    }
}


void Process()
{
    build(1 , n , 1);
    int changes = 0;
    while(q--)
    {
        int op , u ;
        cin >> op >>  u ;
        if(op  == 1)
        {
            changes += u;
            changes %= n;
            continue;
        }
        int v , w;
        cin >> v ;
        u -= changes;
        if(u <= 0)
        {
            u  += n;
        }
        v -=  changes ;
        if(v <= 0)
        {
            v += n;
        }
        if(op == 2)
        {
            cin >> w;
            
            if(u > v)
            {
                int value = get_min(1 , n , 1 , u , n);
                Minimize(value , get_min(1 , n , 1 , 1 , v ));    
                if(update(1 , n , 1 , u , n , w , value))
                {
                    continue;
                }
                update(1 , n , 1 , 1 , v , w , value);
                continue;
            }
            int value = get_min(1 , n , 1 , u , v);
            update(1  , n , 1 , u , v , w , value);
            continue;
        }
        if(u > v)
        {
            cout << get(1 , n , 1  , u , n) + get(1 , n , 1 , 1 ,  v)  <<'\n';
            continue;
        }
        cout << get(1 , n , 1 , u , v) <<'\n';
    }
}



int main()
{
    ios_base :: sync_with_stdio(0);cin.tie(0);
    int test;

    test = 1;
    while(test--)
    {
        Input();
        Process();
    }
    return 0;
}

//Ehem. My code is amazing. Pay me 2$.Thank you.
