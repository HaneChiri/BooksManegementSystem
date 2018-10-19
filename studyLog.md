# UpdateLog

## 2018-10-11

### BUG：账号自增ID

```C++
/*
class Account中的UID并不能直接使用静态类型来自增，而是应该用另一个变量来记录账号数量，
再将这个账号数量定义为UID
*/
//=========在类定义中==========
static int UID;//自增账户id
//改为
static int accountSum;
int UID;

//============在构造函数中=======
accountSum++;
UID=accountSum;

//============在析构函数中=======
accountSum--;
```

## 2018-10-14

### AccountList类访问Account类成员的问题

使用类代替结构体之后，就出现了访问权限的问题。

解决方案一：

    将所有属性增加对应get和set函数来读写。


解决方案二：

    将AccountList类声明为Account类的友元类。似乎不需要前向引用声明，即Account类头文件中不需要包含AccountList的头文件

方案一太麻烦，我就用了方案二，直接声明友元类。

### 字符数组传参问题

构造函数声明里面形参有char*类型：

```C++
Account::Account(char * p_name, bool p_sex, char * p_phoneNumber，
char * p_userName, char * p_password);
```

可是使用的时候常字符串却无法匹配参数类型。

```C++
AccountList::AccountList():accountNum(0)
{
	head = new Account("root", true,"" , "root", "");//参数列表不匹配
}
```

![字符数组传参](_v_images/字符数组传参_1539501399_30217.png)

但是这样写却可以通过编译：

```C++
AccountList::AccountList():accountNum(0)
{
	char name[] = "root";
	char number[] = "";
	char pwd[] = "";
	char userName[] = "root";
	head = new Account(name, true,number , userName, pwd);
}
```

也就是说，**常量指针实参无法传给变量指针形参，因为担心函数内部会修改形参指向的常量。**

于是将形参都改为常量形参

```C++
Account::Account(const char * p_name,const bool p_sex,const char * p_phoneNumber,const char * p_userName,const char * p_password);//将函数形参全部加上const之后，
```

此时对于常量指针形参，与变量指针形参，都可编译。因为形参中的const关键字只是限定了无法在函数内部修改形参指向的地址，这样就可以放心地将常量指针传入。

```C++
AccountList::AccountList():accountNum(0)
{
	char name[] = "root";
	char number[] = "";
	char pwd[] = "";
	char userName[] = "root";
	head = new Account(name, true,number , userName, pwd);
	head = new Account("root", true,"" , "root", "");//两种都可以编译
}
```


### 静态成员无法解析的外部符号（未完全知道原理）

刚开始在Account.h内初始化静态变量，可是却出现了重定义的问题，明明只在这个地方有定义，以下代码是我所有声明时用到的这个静态变量的部分。

![静态变量重定义](_v_images/静态变量重定义_1539502872_24131.png)

```C++
class Account
{
protected:
	static int accountSum;//当前账户数量
  //省略无关部分
};
int Account::accountSum = 0;//初始化
```
当我将初始化那一行给注释掉之后，却又出现了下面的错误——无法解析的外部符号：

    这部分的原因是：只有类中的声明，而没有类外的定义

![静态成员无法解析](_v_images/静态成员无法解析_1539502604_5611.png)

最后我找到的解决方案是，将初始化静态变量那一行给放在类的实现文件里面，即Account.cpp文件中，确实没有了错误。



[静态成员无法解析解决方案](https://blog.csdn.net/wen_eric/article/details/46773197)

### 对象数组初始化方式

[对象数组初始化方式](https://www.cnblogs.com/ruiy/p/8384175.html)

### const指针

```C++
//对指针而言， 顶层const表示指针本身是个常量， 而底层const表示指针所指的对象是一个常量。

int i = 22;
const int ci = 20; //顶层const， 不能修改ci的值
const int *p1= &ci; //底层const， 允许修改p1的值， 但是不能通过*p1修改ci
的值。
int *const p2 = &i; //顶层const， 不能修改p2的值， 但是允许通过*p2修改i
的值
/*
--------------------- 
作者：菠萝小笨笨 
来源：CSDN 
原文：https://blog.csdn.net/xiaokunzhang/article/details/80977375?utm_source=copy 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
```

### BUG：拷贝初始化account总数不自增

```C++
int AccountList::addNode(const Account * p)
{
	Account*q = new Account(*p);//初始化新节点时Account::accountSum不自增
	Account*s = head;//指向链表尾节点
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = q;
	q->next = NULL;
	accountNum++;
	return 0;
}
```

解决方案：写一个拷贝构造函数

### 连续输入

```C++
int Account::changePwd()
{
	char pwd[PWD_LEN];
	char surePwd[PWD_LEN];
	printf("请输入你的密码：\n");
	scanf("%s", pwd);
	if (strcmp(pwd, password) == 0 || printf("密码不匹配！\n"))
	{
		return -1;//未修改
	}
	fflush(stdin);//连续输入需要这个
	printf("请输入你的新密码：\n");
	scanf("%s", pwd);
	fflush(stdin);
	printf("请输入你的确认密码：\n");
	scanf("%s", surePwd);
	if (strcmp(pwd, surePwd) == 0 || printf("确认密码不匹配！\n"))
	{
		return -1;//未修改
	}
	strcpy(password, pwd);
	return 0;

}
```

## 2018-10-19

### c文件操作函数fscanf读取失败（未解决）

```C++
int AccountList::loadData(const char * fileName)
{
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		return -1;
	}
	deleteList();
	Account *data=new Account();//加上括号初始化此对象
	int dataNum = 0;
	while (!feof(fp))//未到文件尾则一直读取
	{
		//UID:姓名:性别:权限:联系方式:用户名:密码
		fscanf(fp, "%d,%s,%d,%d,%s,%s,%s\n",
			&data->UID, data->name, &data->sex, &data->accountType, data->phoneNumber, data->userName, data->password
		);
		addNode(data);
		dataNum++;
	}
	return dataNum;
}

int AccountList::saveData(const char* fileName)
{
	FILE* fp = fopen(fileName,"w");
	if (fp == NULL)
	{
		return -1;
	}
	Account* data = head->next;
	while (data != NULL)
	{
		//UID:姓名:性别:权限:联系方式:用户名:密码
		fprintf(fp, "%d,%s,%d,%d,%s,%s,%s\n",
			data->UID,data->name,data->sex,data->accountType,data->phoneNumber,data->userName,data->password
			);
		data = data->next;
	}
	fclose(fp);
	return registerNum;
}
```
读取时，name属性直接将后面全部读取，没有分隔

解决方案：fscanf的格式字符串后面不带\n，此时不会报错，不过仍然出现name中直接读取后面全部数据的情况。改为以空格为间隔即可。

仍然不知道为什么不能用分隔符，逗号和冒号都试过。

[一样的问题](https://bbs.csdn.net/wap/topics/360040513)

### BUG：UID不唯一

解决方法：
由于UID与username属性重复，将username属性改为UID，删除UID。同时，删除accountNum这个静态属性，用其他方式来确定唯一UID

