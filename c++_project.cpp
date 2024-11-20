#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<limits>
#include<sstream>

using namespace std;


class student{
	
	private:
		int age;
		string id,name,father_name,contact_No,address;
     	double cgpa;                                                  //Student Details and their attributes.
		
	
	
		
		
		public:
			student(){}   //default Constructor.
			
			student(int ag,string i,string n,string f,string y,double z,string a):age(ag),id(i),name(n),father_name(f),contact_No(y),cgpa(z),address(a){} //Parameterized Constructor.
			
			
			//Method functions.
			
			string getid(){
				return id;
			}
			
			double get_result(){
				return cgpa;
			}
			
			string getname(){
				return name;
			}
			
			string getaddress(){
				return address;
			}
			
			int getage(){
				return age;
			}
			
			string getcontact(){
				return contact_No;
			}
			
			string getfathername(){
				return father_name;
			}
			
			
			void display(){
				cout<<setw(10)<<id<<"   "<<setw(20)<<name<<setw(5)<<age<<setw(20)<<father_name<<setw(15)<<contact_No<<setw(5)<<cgpa<<setw(30)<<address<<endl;
				 
			}
			
			
			void setage(int x){
				age=x;
			}
			
			void setcgpa(double x){
				cgpa=x;
			}
			
			
	
	
}; 


void menu(bool isadmin){
	
	
	cout<<endl<<endl;
	cout<<setw(15)<<"Student Database Management System"<<endl;
	cout<<string(50,'-')<<endl;
	
	if(isadmin){
	
	cout<<"1-Add student"<<endl;
	cout<<"2-display student details"<<endl;                       //admin user to prefer
	cout<<"3-search student using ID"<<endl;
	cout<<"4-delete student using ID"<<endl;
	cout<<"5-Update student"<<endl;
	cout<<"6-Clear the data from Saved file"<<endl;
	cout<<"7-Save the file and exit"<<endl<<endl;
	
}else{
	cout<<"1-display student details"<<endl;                       //student user to prefer
	cout<<"2-exit"<<endl<<endl;
}

cout<<"Enter the choice:"<<endl;
	
}


void savetofile(vector<student> &students,string file){
	
	
	ofstream obj(file,ios::out);
	
	
	
	for(int i=0;i<students.size();i++){
		obj<<students[i].getid()<<" , "<<students[i].getname()<<" , "<<students[i].getage()<<" , "<<students[i].get_result()<<" , "<<students[i].getfathername()<<" , "<<students[i].getcontact()<<" , "
		<<students[i].getaddress();
	}
	
	cout<<"Data saved successfully.."<<endl;
	
}

void loadfromfile(vector<student> &students,string file){
	
	ifstream obj(file);
	
	
	if(!obj){
		cout<<endl<<"No existing records are found..!"<<endl;
		
		return;
	}else{
	     int age;
		string id,name,father_name,contact_No,address,line;
     	double cgpa;
     	
     	while(getline(obj,line)){
     		stringstream ss(line);
     		string convert;
     		getline(ss,id,',');
     		getline(ss,name,',');
     		getline(ss,convert,',');age=stoi(convert);
     		getline(ss,convert,',');cgpa=stod(convert);
     		getline(ss,father_name,',');
     		getline(ss,contact_No,',');
     		getline(ss,address,',');
     		
     		students.emplace_back(age,id,name,father_name,contact_No,cgpa,address);
		 }
     	
     	cout<<"Data loaded successfully..!"<<endl;
     	
	}
	
	
	
	
}

void clearfile(string file, vector<student> &students) {
    ofstream obj(file, ios::trunc); // Open file in truncate mode
    if (obj) {
        students.clear(); // Clear the in-memory student list
        cout << "All data deleted successfully from the file and memory." << endl;
    } else {
        cout << "Error: Unable to clear the file." << endl;
    }
}





int main(){
	  
	  vector<student> students;
	  string pass,id;
	  int age;
	  double cgpa;
	  cout<<"Enter the role admin (or) Student: "<<endl;
	  
	  string role;
	  cin>>role;
	  
	  bool isadmin=false;
	  
	  if(role=="admin"){
	  	 cout<<"Enter password:";
	  	 cin>>pass;
	  	 
	  	 if(pass=="Srmap123"){
	  	 	  cout<<endl<<"Admin login successful!"<<endl;
	  	 	  isadmin=true;
		   }else{
		   	cout<<"Incorrect password"<<endl;
		   	
		   }
	
	  }else	if(role=="student"){
	  		cout<<"Student login succesful!"<<endl;
		  
	        
	  }else{
	  	cout<<"Login failed"<<endl;
	  }
	  string file="students.txt";
	  
	  loadfromfile(students,file);
	

	    int choice;
	  do{
	  	    
	  	menu(isadmin);
	  if(isadmin){

	  	      cin>>choice;
	  	      
	  	      switch(choice){
	  	      	
	  	      	case 1:{
	            	string name,father_name,contact_No,address;
	  	      		cout<<"Enter student id: ";
	  	      		cin>>id;
	  	      		for(int i=0;i<students.size();i++){
	  	      			   if(students[i].getid()==id){
	  	      			   	cout<<"ID already exits.Try again!"<<endl;
	  	      			   	break;
							   }
						}
	  	      	
	  	      	    cin.ignore();
	  	      		cout<<endl<<"Enter Student Name: ";
	  	      		getline(cin,name);
	  	      		cout<<endl<<"Enter Student age: ";
	  	      		cin>>age;
	  	      		cout<<endl<<"Enter student's Father name: ";
	  	      		cin.ignore();
	  	      		getline(cin,father_name);
	  	      		cout<<endl<<"Enter student's contact info: ";
	  	      		cin>>contact_No;
	  	      		cout<<endl<<"Enter cgpa: ";
	  	      		cin>>cgpa;
	  	      		cin.ignore();
	  	      		cout<<endl<<"Enter address: ";
	  	      		getline(cin,address);
	  	      		students.emplace_back(age,id,name,father_name,contact_No,cgpa,address);
	  	      		cout<<"Student added successfully!"<<endl;
	  	      		
	  	      	
	  	      	    break; 
	  	      }
	  	      	case 2:{
	  	      		
	  	      		if(students.empty()){
	  	      			cout<<"No records are found."<<endl;
						}else{
							cout<<endl;
							cout<<left<<setw(5)<<"Sl.NO   "<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(5)<<"Age"<<setw(20)<<"Father Name"<<setw(15)<<"Contact info"<<setw(5)<<" CGPA "<<setw(30)<<"Student's Address"<<endl;
								cout<<string(110,'-')<<endl; 
							for(int i=0;i<students.size();i++){
								cout<<left<<setw(5)<<i+1;
							  students[i].display();
							}
							
						}
						
						break;
				}
				case 3:
						{
						
						cout<<"Enter the student id to search:  ";
						cin>>id;
						cout<<endl;
						bool found=false;
						for(int i=0;i<students.size();i++){
								
								if(students[i].getid()==id){
									found=true;
									cout<<"  Student details Found:  "<<endl;
							        cout<<left<<setw(5)<<"Sl.NO   "<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(5)<<"Age"<<setw(20)<<"Father Name"<<setw(15)<<"Contact info"<<setw(5)<<" CGPA "<<setw(30)<<"Student's Address"<<endl;
									students[i].display();
								}
						
					}
					
					if(!found){
						cout<<"student with the id doesn't Exist."<<endl;
					}
	  	      		  
	  	      		  
	  	      		  break;
	  	      	}
	  	      	 case 4:
	  	      	 	{
						 
	  	      	 	cout<<"Enter the student id to delete: ";
	  	      	 	cin>>id;
	  	      	 	cout<<endl;
	  	      		bool found=false;
	  	      		
	  	      		for(int i=0;i<students.size();i++){
	  	      			if(students[i].getid()==id){
							
	  	      		found=true;	
	  	      		for(int j=i;j<students.size()-1;j++){
	  	      			  students[j]=students[j+1];
						}
					
						students.pop_back();  //Remove the last duplicate element.
	  	      		cout<<"Student Record deleted successfully."<<endl;
	  	      		break;
	  	      	}
	  	    
	  	      	
	  	      }
	  	      	
	  	      	if(!found){
						cout<<"student with the id doesn't Exist."<<endl;
					}
	  	      	
	  	  
	  	  
	  	  break;
	  }
	  	  case 5:
	  	  	
	  	{
		
	  	  	cout<<"enter the id to update: ";
	  	  	cin>>id;
	  	  	cout<<endl;
	  	  	bool found=false;
	  	  	for(int i=0;i<students.size();i++){
	  	      	if(students[i].getid()==id){
	  	      		cout<<"Update age: ";
	  	      		cin>>age;
	  	      		cout<<endl;
	  	      		cout<<"Update cgpa: ";
	  	      		cin>>cgpa;
	  	      		cout<<endl;
	  	      		
	  	      		students[i].setage(age);
	  	      		students[i].setcgpa(cgpa);
	  	      		found=true;
	  	      		cout<<"Student details updated successfully!"<<endl;
	  	      		
	  	      	}
	  	      	
	  	      }
	  	      
	  	      if(!found){
						cout<<"student with the id doesn't Exist."<<endl;
					}
	  	      		
	  	      	break;	
	  	  	
	  	  	
	  	  }
	  	  	 case 6:
					
				   clearfile(file,students);
	  	  	 	   break;
	  	  	 	   
				  
				  
	  	      case 7:
	  	      	   savetofile(students,file);
	  	      	   break;
	  	      	    
	  	  		default:
					     cout<<"Invalid choice....Please try again!"<<endl;	
								  
}
	  	  	
	  	  	}else{
	  	  			cin>>choice;
	  	  			
	  	  			switch(choice){
	  	  				
	  	  				case 1:
	  	  					{
								
	  	  			cout<<left<<setw(5)<<"Sl.NO   "<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(5)<<"Age"<<setw(20)<<"Father Name"<<setw(15)<<"Contact info"<<setw(5)<<" CGPA "<<setw(30)<<"Student's Address"<<endl;
	  	  			cout<<string(110,'-')<<endl;
					       for(int i=0;i<students.size();i++){
								cout<<left<<setw(5)<<i+1;
							  students[i].display();
							}
						
						
						break;
					}
					
					
	  	  			case 2:
						cout<<"Exited..."<<endl;
						break;
						
					default:
					     cout<<"Invalid choice....Please try again!"<<endl;	
								  
						}
				}
	  	      	
				}while((isadmin &&choice!=7) || (!isadmin && choice!=2));
	  	      
	  	      
	  	      
	  	      return 0;
	  }
	   






