#include"Functions.h"
int main()
{
	// reading data from files 
	idx_read();
	car_read();
	cust_read();
	rtl_read();
	admin_read();
	ReadTypes();
	ReadBrances();

	///////////////////////////
    
	string choice;
	do
	{
		system("cls");
		int counter = 1;
		bool found;

		do
		{
			cout << "#-------------------------> welcome to the program <-------------------------#\n\n";
			cout << " -->if you want to enter as an admin : \n \tuse (mostafa@admin.crc) as user name \n \tuse (mostafa12345) as password " << "\n\n";
			cout << " -->if you want to enter as a user : \n \t use (mostafa@customer.crc) as user name \n \t use (mostafa123) as password " << "\n\n";

			string use, pass;
			cout << "#------> Enter Your User Name   :  ";
			get(use);
			cout << "#------> Enter Your Password    :  ";
			getPassword(pass);	
			counter++;
			found = false;

			for (int i = 0; i < adm_size; i++)
				if (use == arr_admin[i].usr_name && pass == arr_admin[i].password)
				{
					found = true;
					break;;
				}

			if (found)
			{
				do {
					system("cls");
					string num;
					cout << "#--------------------------->  WELCOME To Admin Department <--------------------------# \n\n";
					cout << "#-----> If you want to Add new car,           Enter       1\n";
					cout << "#-----> If you want to Add new customer,      Enter       2\n";
					cout << "# ----->If you want to Delete car,            Enter       3\n";
					cout << "#-----> If you want to Disply Cars,           Enter       4\n";
					cout << "#-----> If you want to Disply Customers,      Enter       5\n";
					cout << "#-----> If you want to Edit car detalis       Enter       6\n";
					cout << "#-----> If you want to View company Profits   Enter       7\n";
					cout << "#-----> If you want to Log out,               Enter  anything else\n";
					cout << "\n#------> Enter Your choise : ";
					get(num);
					if (num == "1")
						add_car();
					else if (num == "2")
						add_customer();
					else if (num == "3")
						delet();
					else if (num == "4")
						dis();
					else if (num == "5")
						dis_cust();
					else if (num == "6")
						edit_car();
					else if (num == "7")
						profit();
					else
					{
						cout << "#------------------>> Thank You <<------------------#\n\n";
						Sleep(3000);
						system("cls");
						break;
					}
				} while (true);
				
				break;
			}

			for (int i = 0; i < cust_idx; i++)
				if (use == arr_cust[i].us_name && pass == arr_cust[i].pass)
				{
					found = true;
					break;
				}

			if (found)
			{
				do {
					system("cls");
					string num;
					cout << "#-------------------------> WELCOME To User Department <------------------------#\n\n";
					cout << "#-----> If you want to Search for available cars    Enter        1\n";
					cout << "#-----> If you want to Reserve a car                Enter        2\n";
					cout << "#-----> If you want to View your profile            Enter        3\n";
					cout << "#-----> If you want to Change your password         Enter        4\n";
					cout << "#-----> If you want to Log out                      Enter    anything else \n\n";
					
					cout << "\n#------> Enter Your choise : ";
					get(num);

					if (num == "1")
						c_search();
					else if (num == "2")
						reserve(use);
					else if (num == "3")
					{
						string use_id;
						int indxx;
						cust_search_usr(use, use_id, indxx);
						user_profile(use_id, indxx);						
					}
					else if (num == "4")
					{
						string cs_id;
						int us_idx ;
						cust_search_usr(use, cs_id, us_idx);
						change_pass(us_idx);
					}
					else
					{
						cout << "#------------------>> Thank You <<------------------#\n\n";
						Sleep(3000);
						system("cls");
						break;
					}

				} while (true);
				
				break;
			}
			else
			{
				cout << "\a";
				cout << "\n#------>The user name or password is incorrect\n";
				cout << "#------>You still have " << 4 - counter << " attempets\n";
				
				if (counter != 4)
				{
					Sleep(3000);
					system("cls");
				}
				else if (counter == 4)
				{
					cout << "#-------------------------------------------------------------#\n\n";
				}
			}
		} while (!found && counter <= 3);  // he will continue untill he enter valid user name or password
		cout << "#-------------------------> welcome to the program <-------------------------#\n\n";

		cout << "#------> To continue in the program Enter \"y\" or \"Y\"\n"
			 << "#------> To exit from the program   Enter anything else\n\n";
		cout << "#------> Enter Your choice : ";
		get(choice);
	} while (choice == "y" || choice == "Y");	
	
	cout << "#------------------>> Thank You <<------------------#\n\n";

	//writing data in files
	car_write();
	cust_write();
	rtl_write();
	idx_write();
	///////////////////////

	return 0;
}
