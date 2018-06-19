#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;

struct student
{
	string name;
	string sex;
	double score;
};

bool compare1(const student&a,const student&b)
{
	return a.score>b.score;
}

bool compare2(const student&a,const student&b)
{
	return a.name<b.name;
}

int main()
{
	ifstream ifs("score.csv");
	string name,sex;

	int count=0,mcount=0,fmcount=0;
	double score=0,total=0,mscore=0,fmscore=0;

	vector<student>stu;

	while(ifs)
	{
		ifs>>name>>sex>>score;
		student s;
		name.erase(std::remove(name.begin(),name.end(),','),name.end());
		sex.erase(std::remove(sex.begin(),sex.end(),','),sex.end());

		s.name=name;
		s.sex=sex;
		s.score=score;

		stu.push_back(s);

		total+=score;
		count++;

		if(sex.length()!=6)
		{
			mcount++;
			mscore+=score;
		}
		else
		{
			fmcount++;
			fmscore+=score;
		}
	}

	sort(stu.begin(),stu.end(),compare1);
	sort(stu.begin(),stu.end(),compare2);

	cout<<left<<setw(9)<<"Name"<<left<<setw(10)<<"Sex"<<"Score"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<left<<setw(9)<<stu[i].name<<left<<setw(10)<<stu[i].sex<<stu[i].score<<endl;
	}

	cout<<"male's average = "<<mscore/mcount<<endl;
	cout<<"female's average = "<<fmscore/fmcount<<endl;
	cout<<"average = "<<total/count<<endl;
	
	return 0;
}
