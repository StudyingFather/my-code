#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct pig
{
 int front,next;//以链式结构存储该猪之前的猪和下一只猪
 int id;//猪的身份
        //0为主猪（MP），1为忠猪（ZP），2为反猪（FP）
 int hp;//当前生命值
 int used_card;//该猪累计摸到的牌数（不是当前手中牌数）
 int global_id;//对外展示的身份
               //0为未暴露身份，1为已经暴露身份，2为类反猪
 bool zb;//是否装备诸葛连弩
 bool alive;//是否存活
 char card[2005];//该猪摸过的所有牌
 bool is_used[2005];//对应位置的牌是否使用过
}p[15];
int n,m,curc=1;//curc：牌堆顶端位置
int alive_fp;//存活猪的数量
int res=-1;//游戏结果
           //-1：游戏未结束，0：主猪胜，1：反猪胜
char que[2005];//card queue(a.k.a. pai dui)
bool clear_mark;//主猪牌堆清空标记（防止意外标记）
void judge_identity(int cur)//判断身份
{
 char s[5];
 scanf("%s",s);
 if(s[0]=='M')p[cur].id=0,p[cur].global_id=1;
 else if(s[0]=='Z')p[cur].id=1;
 else p[cur].id=2,alive_fp++;
}
void get_initial_card(int cur)//读入初始牌
{
 char s[5];
 for(int i=1;i<=4;i++)
 {
  scanf("%s",s);
  p[cur].used_card++;
  p[cur].card[i]=s[0];
 }
}
void get_card(int cur)//编号为cur的猪摸一张牌
{
 p[cur].card[++p[cur].used_card]=que[curc];
 if(curc!=m)curc++;//牌堆用完的时候，要一直摸最后一张牌
}
void die(int cur,int killer)//编号为cur的猪正处在濒死状态，杀手为killer
{
 for(int i=1;i<=p[cur].used_card;i++)
  if(p[cur].card[i]=='P'&&p[cur].is_used[i]==false)
  {
   p[cur].hp++;
   p[cur].is_used[i]=true;
   if(p[cur].hp>0)return;//该猪摆脱了濒死状态
  }
 p[cur].alive=false;//将该猪标记为死亡
 p[p[cur].front].next=p[cur].next;//改变出牌顺序
 p[p[cur].next].front=p[cur].front;
 if(p[cur].id==0)//主猪死亡，反猪胜利
 {
  res=1;
  return;
 }
 if(p[cur].id==2)
 {
  alive_fp--;
  if(alive_fp==0)//先判断游戏胜利条件是否达成，如果达成，就不再摸牌了
  {
   res=0;
   return;
  }
  get_card(killer),get_card(killer),get_card(killer);//杀死反猪的猪摸3张牌
 }
 else if(p[cur].id==1&&killer==1)//主猪杀死忠猪，弃置所有手牌和装备
 {
  p[1].used_card=0;//清空牌堆
  memset(p[1].card,0,sizeof(p[1].card));
  memset(p[1].is_used,false,sizeof(p[1].is_used));
  p[1].zb=false;//卸掉装备
  clear_mark=true;//防止牌打出状态被意外改变
 }
}
bool use_peach(int cur)//编号为cur的猪使用一张桃
{
 if(p[cur].hp<4)//生命未满的时候就吃掉
 {
  p[cur].hp++;
  return true;
 }
 else return false;//生命满的时候就不吃桃了
}
bool use_wxkj(int cur,int sit)
//轮到编号cur的猪出无懈可击，锦囊牌的目标为sit一方（1代表主猪一方，2代表反猪一方）
{
 int curp=cur;
 do
 {
  if(p[curp].id!=2&&sit==1)
  {
   for(int i=1;i<=p[curp].used_card;i++)
    if(p[curp].card[i]=='J'&&p[curp].is_used[i]==false)
    {
     p[curp].is_used[i]=true;
     if(p[curp].global_id!=1)p[curp].global_id=1;
     return !use_wxkj(curp,2);//轮到相反一方出无懈可击
    }
  }
  if(p[curp].id==2&&sit==2)
  {
   for(int i=1;i<=p[curp].used_card;i++)
    if(p[curp].card[i]=='J'&&p[curp].is_used[i]==false)
    {
     p[curp].is_used[i]=true;
     if(p[curp].global_id!=1)p[curp].global_id=1;
     return !use_wxkj(curp,1);
    }
  }
  curp=p[curp].next;
 }while(curp!=cur);
 return false;
}
void use_shan(int cur)//编号为cur的猪需要打出一张闪来响应杀
{
 bool used_shan=false;
 for(int i=1;i<=p[cur].used_card;i++)
  if(p[cur].card[i]=='D'&&p[cur].is_used[i]==false)
  {
   used_shan=true;
   p[cur].is_used[i]=true;
   break;
  }
 if(!used_shan)p[cur].hp--;//没有闪时要掉血
}
bool use_kill(int cur)//编号为cur的猪打出一张杀
{
 if(p[cur].id==2)//反猪会对主猪和跳忠的猪打出杀
 {
  if(p[p[cur].next].global_id==1&&(p[p[cur].next].id==1||p[p[cur].next].id==0))
  {
   p[cur].global_id=1;
   use_shan(p[cur].next);//被杀的猪响应闪
   if(p[p[cur].next].hp<=0)die(p[cur].next,cur);//濒死状态判定
   return true;
  }
 }
 else if(p[cur].id==1)//忠猪会对跳反的猪打出杀
 {
  if(p[p[cur].next].global_id==1&&p[p[cur].next].id==2)
  {
   p[cur].global_id=1;
   use_shan(p[cur].next);
   if(p[p[cur].next].hp<=0)die(p[cur].next,cur);
   return true;
  }
 }
 else //主猪会对跳反的猪或类反猪打出杀
 {
  if((p[p[cur].next].global_id==2)||(p[p[cur].next].global_id==1&&p[p[cur].next].id==2))
  {
   use_shan(p[cur].next);
   if(p[p[cur].next].hp<=0)die(p[cur].next,cur);
   return true;
  }
 }
 return false;//没有可以打出杀的对象
}
void battle(int attacker,int defender)//执行决斗过程
{
 if(attacker==1&&p[defender].id==1)//忠猪在与主猪决斗时，必定掉血
 {
  p[defender].hp--;
  if(p[defender].hp<=0)die(defender,attacker);
  return;
 }
 int curp=defender;
 while(1)
 {
  bool flag=false;
  for(int i=1;i<=p[curp].used_card;i++)
   if(p[curp].card[i]=='K'&&p[curp].is_used[i]==false)
   {
    p[curp].is_used[i]=true;
    flag=true;
    break;
   }
  if(flag)curp=(curp==defender?attacker:defender);//轮到对方弃置杀
  else
  {
   p[curp].hp--;
   if(p[curp].hp<=0)die(curp,attacker==curp?defender:attacker);//没有受到伤害的一方为伤害来源
   return;
  }
 }
}
bool use_fight(int cur)//编号为cur的猪打出一张决斗
{
 if(p[cur].id==2)//反猪决斗时总是找主猪
 {
  p[cur].global_id=1;
  bool flag=use_wxkj(cur,1);
  if(!flag)battle(cur,1);//执行决斗过程
  return true;//无论该锦囊是否被无懈，该锦囊都已经被打出
 }
 else if(p[cur].id==1)
 {
  for(int i=p[cur].next;i!=cur;i=p[i].next)
   if(p[i].global_id==1&&p[i].id==2)//忠猪找跳反的猪决斗
   {
    p[cur].global_id=1;
    bool flag=false;
    if(p[i].global_id==1)flag=use_wxkj(cur,2);
    if(!flag)battle(cur,i);
    return true;
   }
 }
 else
 {
  for(int i=p[cur].next;i!=cur;i=p[i].next)
   if((p[i].global_id==1&&p[i].id==2)||p[i].global_id==2)//主猪找跳反的猪和类反猪
   {
    bool flag=false;
    if(p[i].global_id==1)flag=use_wxkj(cur,2);
    if(!flag)battle(1,i);
    return true;
   }
 }
 return false;//没有目标可以进行决斗
}
bool use_zgln(int cur)//编号为cur的猪装备诸葛连弩
{
 p[cur].zb=true;
 return true;
}
bool use_nzrq(int cur)//编号为cur的猪打出南蛮入侵
{
 for(int i=p[cur].next;i!=cur;i=p[i].next)
 {
  bool used_kill=false;
  if(p[i].global_id==1)//只有暴露身份的猪才有其他猪对它使用无懈可击
   if(use_wxkj(cur,p[i].id==0?1:p[i].id))continue;
  //需要注意，无懈可击只会免除对一个目标的锦囊效果，并不会使整个锦囊失效
  for(int j=1;j<=p[i].used_card;j++)
   if(p[i].card[j]=='K'&&p[i].is_used[j]==false)
   {
    p[i].is_used[j]=true;
    used_kill=true;
    break;
   }
  if(!used_kill)
  {
   p[i].hp--;
   if(p[i].hp<=0)die(i,cur);
   if(i==1&&p[cur].global_id==0)p[cur].global_id=2;
   //没暴露身份，且对主猪造成伤害的猪会被判断为类反猪
   if(res!=-1)return true;//一旦游戏结束条件达成，立刻终止锦囊结算过程
  }
 }
 return true;
}
bool use_wjqf(int cur)
{
 for(int i=p[cur].next;i!=cur;i=p[i].next)
 {
  bool used_kill=false;
  if(p[i].global_id==1)
   if(use_wxkj(cur,p[i].id==0?1:p[i].id))continue;
  for(int j=1;j<=p[i].used_card;j++)
   if(p[i].card[j]=='D'&&p[i].is_used[j]==false)
   {
    p[i].is_used[j]=true;
    used_kill=true;
    break;
   }
  if(!used_kill)
  {
   p[i].hp--;
   if(p[i].hp<=0)die(i,cur);
   if(i==1&&p[cur].global_id==0)p[cur].global_id=2;
   if(res!=-1)return true;
  }
 }
 return true;
}
void get_initial_info(int cur)//读取每只猪的身份，初始手牌，并做初始化
{
 judge_identity(cur);
 get_initial_card(cur);
 if(cur==1)p[cur].front=n;
 else p[cur].front=cur-1;
 if(cur==n)p[cur].next=1;
 else p[cur].next=cur+1;
 p[cur].alive=true;
 p[cur].hp=4;
}
void get_card_queue()//读入牌堆
{
 for(int i=1;i<=m;i++)
 {
  char s[5];
  scanf("%s",s);
  que[i]=s[0];
 }
}
int main()
{
 //准备阶段开始
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  get_initial_info(i);
 get_card_queue();
 //准备阶段结束
 //游戏阶段开始
 while(res==-1)
  for(int i=1;i<=n;i=p[i].next)
  {
   get_card(i),get_card(i);//摸牌阶段，摸两张牌
   int use_kill_num=0;
   //没有装备诸葛连弩的猪一回合只能使用一张杀
   for(int j=1;j<=p[i].used_card;j++)
    if(!p[i].is_used[j])//没有使用该手牌就使用它
    {
     bool is_used=false;
     if(p[i].card[j]=='P')is_used=use_peach(i);//吃桃
     else if(p[i].card[j]=='K')//使用杀
     {
      if(use_kill_num==0||p[i].zb)is_used=use_kill(i);
      if(is_used)use_kill_num++;
     }
     else if(p[i].card[j]=='F')is_used=use_fight(i);//打出决斗
     else if(p[i].card[j]=='Z')is_used=use_zgln(i);//装备诸葛连弩
     else if(p[i].card[j]=='N')is_used=use_nzrq(i);//打出南蛮入侵
     else if(p[i].card[j]=='W')is_used=use_wjqf(i);//打出万箭齐发
     if(is_used)
     {
      if(i==1&&clear_mark)clear_mark=false;//这句话是为了避免一个小bug
	  else p[i].is_used[j]=true;
      j=0;//使用一张手牌可能会导致前面的手牌变为可用，因此要从头开始判断每一张牌
     }
     if(!p[i].alive)break;//如果该猪已经死亡，就结束它的阶段
     if(res!=-1)break;//一旦达成胜利条件，游戏立刻终止
    }
   if(res!=-1)break;//一旦达成胜利条件，游戏立刻终止
  }
 //游戏阶段结束
 //输出结果阶段开始
 if(res==0)puts("MP");
 else puts("FP");
 for(int i=1;i<=n;i++)
 {
  if(!p[i].alive)
  {
   puts("DEAD");
   continue;
  }
  for(int j=1;j<=p[i].used_card;j++)
   if(!p[i].is_used[j])printf("%c ",p[i].card[j]);
  puts("");
 }
 //输出结果阶段结束
 return 0;
}