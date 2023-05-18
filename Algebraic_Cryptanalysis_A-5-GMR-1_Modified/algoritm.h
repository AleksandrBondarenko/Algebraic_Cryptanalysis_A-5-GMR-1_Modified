#pragma once

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <iterator>
#include <set>

using namespace std;





int algoritm(unsigned __int64 all_mask) {
	std::cout << "start\n";
	unsigned int reg_1 = 0;
	unsigned int reg_2 = 0;
	unsigned int reg_3 = 0;
	unsigned int reg_4 = 0;
	unsigned int key = 0;
	unsigned int n = 800;
	unsigned int keytmp = 0;
	unsigned int first_degree_x[19];
	unsigned int first_degree_y[22];
	unsigned int first_degree_z[23];
	char tmp;
	int pos;
	bool ind;
	ifstream system_x_input("system_x.txt");
	ifstream system_y_input("system_y.txt");
	ifstream system_z_input("system_z.txt");
	ifstream fingamma("gamma.txt");
	vector<bitset<720>> vector1(1000);
	vector<bitset<720>> vector2(1000);
	vector<bitset<720>> vector3(1000);
	vector<bitset<720>> matrix(800);
	bitset<1000> gamma;
	vector<bitset<65>> keyvector(77);

	ifstream first_degree_x_input("first_degree_x.txt");
	ifstream first_degree_y_input("first_degree_y.txt");
	ifstream first_degree_z_input("first_degree_z.txt");

	ifstream fin_nav("navigator.txt");
	if (!system_x_input.is_open() || !system_y_input.is_open() || !system_z_input.is_open() || !first_degree_x_input.is_open() || !first_degree_y_input.is_open() ||
		!first_degree_z_input.is_open() || !fingamma.is_open())
	{
		cout << "Some of files did not open!\n";

		return 1;
	}

	for (int i = 0; i < vector1.size(); i++) {
		for (int k = 0; k < 190; k++) {
			if (k == 0)
				system_x_input >> tmp;
			system_x_input >> tmp;
			vector1[i][k] = tmp;
		}

	}
	for (int i = 0; i < vector2.size(); i++) {
		for (int k = 190; k < 443; k++) {
			if (k == 190)
				system_y_input >> tmp;
			system_y_input >> tmp;
			vector2[i][k] = tmp;
		}

	}
	for (int i = 0; i < vector3.size(); i++) {
		for (int k = 443; k < 719; k++) {
			if (k == 443)
				system_z_input >> tmp;
			system_z_input >> tmp;
			vector3[i][k] = tmp;
		}

	}
	fingamma.seekg(0, std::ios::end);
	n = fingamma.tellg();
	cout << "gamma size " << n << endl;
	fingamma.seekg(0, std::ios::beg);
	
	for (int i = 0; i < n; i++) {
		fingamma >> tmp;
		gamma[i] = tmp;
	}
	system_x_input.close();
	system_y_input.close();
	system_z_input.close();
	fingamma.close();
	

	for (int i = 18; i >= 0; i--) {
		first_degree_x_input >> first_degree_x[i];
		first_degree_x[i] -= 1;
	}
	for (int i = 21; i >= 0; i--) {
		first_degree_y_input >> first_degree_y[i];
		first_degree_y[i] -= 2;
	}
	for (int i = 22; i >= 0; i--) {
		first_degree_z_input >> first_degree_z[i];
		first_degree_z[i] -= 3;
	}
	first_degree_x_input.close();
	first_degree_y_input.close();
	first_degree_z_input.close();
	vector <bitset<720>>::iterator it;
	vector <bitset<720>>::iterator it1;
	vector <bitset<720>>::iterator it2;
	vector <bitset<720>>::iterator it3;

	vector<bitset<720>> r_vector1(1000);
	vector<bitset<720>> r_vector2(1000);
	vector<bitset<720>> r_vector3(1000);

	// 184473 3604887 3328737 81795
//101101000010011001 1101110000000110010111 1100101100101011100001 
	int count = 0;




	unsigned int mask;

	unsigned int mask_1 = 0;
	unsigned int mask_2 = 0;
	unsigned int mask_3 = 0;

	unsigned int val;

	unsigned int navigator[276];

	unsigned int pos_1 = 0;
	unsigned int pos_2 = 0;
	unsigned int pos_3 = 0;

	unsigned int val_1 = 0;
	unsigned int val_2 = 0;
	unsigned int val_3 = 0;

	unsigned int final_size_1 = 0;
	unsigned int final_size_2 = 0;
	unsigned int final_size_3 = 0;

	unsigned int count_val_1 = 0;
	unsigned int count_val_2 = 0;
	unsigned int count_val_3 = 0;

	unsigned int max_val_1 = 0;
	unsigned int max_val_2 = 0;
	unsigned int max_val_3 = 0;

	for (int i = 0; i < 276; i++) {
		fin_nav >> navigator[i];

	}
	fin_nav.close();
	pos_1 = ((pos_1 | all_mask) & 0x7FFFF);
	pos_2 = ((pos_2 | (all_mask >> 19)) & 0x3FFFFF);
	pos_3 = ((pos_3 | (all_mask >> 41)) & 0x7FFFFF);


	for (int p = 0; p < 19; p++) {
		if (((pos_1 >> p) & 1)) {
			count_val_1++;
		}

	}
	for (int p = 0; p < 22; p++) {
		if (((pos_2 >> p) & 1)) {
			count_val_2++;
		}

	}
	for (int p = 0; p < 23; p++) {
		if (((pos_3 >> p) & 1)) {
			count_val_3++;
		}

	}
	for (int i = 0; i < count_val_1; i++) {
		max_val_1 = ((max_val_1 << 1) | 1);
	}
	for (int i = 0; i < count_val_2; i++) {
		max_val_2 = ((max_val_2 << 1) | 1);
	}
	for (int i = 0; i < count_val_3; i++) {
		max_val_3 = ((max_val_3 << 1) | 1);
	}
	for (int i_1 = 0; i_1 <= max_val_1; i_1++) {

		// val_1
		val = i_1;
		val_1 = 0;
		for (int i = 0; i < 19; i++) {
			if ((pos_1 & (1 << i))) {
				val_1 = (val_1 | ((val & 1) << i));
				val = (val >> 1);
			}
		}


		for (int i_2 = 0; i_2 <= max_val_2; i_2++) {

			// val_2
			val = i_2;
			val_2 = 0;
			for (int i = 0; i < 22; i++) {
				if ((pos_2 & (1 << i))) {
					val_2 = (val_2 | ((val & 1) << i));
					val = (val >> 1);
				}
			}


			for (int i_3 = 0; i_3 <= max_val_3; i_3++) {

				// val_3
				val = i_3;
				val_3 = 0;
				for (int i = 0; i < 23; i++) {
					if ((pos_3 & (1 << i))) {
						val_3 = (val_3 | ((val & 1) << i));
						val = (val >> 1);
					}
				}

				
				for (int i = 0; i < r_vector1.size(); i++)
				{
					r_vector1[i].reset();
					r_vector1[i] ^= vector1[i];
				}
				for (int i = 0; i < r_vector2.size(); i++)
				{
					r_vector2[i].reset();
					r_vector2[i] ^= vector2[i];
				}
				for (int i = 0; i < r_vector3.size(); i++)
				{
					r_vector3[i].reset();
					r_vector3[i] ^= vector3[i];
				}
	
				///111 
				mask_1 = 0;
				for (int p = 0; p < 19; p++) {
					if ((pos_1 & (1 << p)) != 0) {
						mask_1 = (pos_1 & (1 << p));
						val = ((val_1 >> p) & 1);
					}
					if ((pos_1 >> p) == 0) {
						break;
					}
					if (mask_1) {
						for (int k = 0; k < 1000; k++) {
							for (int i = 0; i < 190; i++) {

								if ((navigator[i] & mask_1) != 0) {

									if (r_vector1[k].test(i)) {

										for (int j = 0; j < 190; j++) {
											if ((navigator[i] ^ mask_1) == 0) {
												if (val != 0) {
													if (r_vector1[k].test(719)) {
														r_vector1[k][719] = 0;
													}
													else {
														r_vector1[k][719] = 1;
													}
												}
												break;
											}

											if (navigator[j] == (navigator[i] ^ mask_1)) {
												if (val != 0) {
													if (r_vector1[k].test(j)) {
														r_vector1[k][j] = 0;
													}
													else {
														r_vector1[k][j] = 1;
													}
												}

												break;
											}
										}
										r_vector1[k][i] = 0;
									}//if
								}
							}

						}
					}//if(mask_1)
				}
				////2
				mask_2 = 0;
				for (int p = 0; p < 22; p++) {
					if ((pos_2 & (1 << p)) != 0) {
						mask_2 = (pos_2 & (1 << p));
						val = ((val_2 >> p) & 1);
					}
					if ((pos_2 >> p) == 0) {
						break;
					}
					if (mask_2) {
						for (int k = 0; k < 1000; k++) {
							for (int i = 0; i < 253; i++) {
								if ((navigator[i] & mask_2) != 0) {

									if (r_vector2[k].test(i + 190)) {

										for (int j = 0; j < 253; j++) {
											if ((navigator[i] ^ mask_2) == 0) {
												if (val != 0) {
													if (r_vector2[k].test(719)) {
														r_vector2[k][719] = 0;
													}
													else {
														r_vector2[k][719] = 1;
													}
												}
												break;
											}

											if (navigator[j] == (navigator[i] ^ mask_2)) {
												if (val != 0) {
													if (r_vector2[k].test(j + 190)) {
														r_vector2[k][j + 190] = 0;
													}
													else {
														r_vector2[k][j + 190] = 1;
													}
												}

												break;
											}
										}
										r_vector2[k][i + 190] = 0;
									}//if
								}
							}

						}
					}//if(mask_2)
				}

				////3
				mask_3 = 0;
				for (int p = 0; p < 23; p++) {
					if ((pos_3 & (1 << p)) != 0) {
						mask_3 = (pos_3 & (1 << p));
						val = ((val_3 >> p) & 1);
					}
					if ((pos_3 >> p) == 0) {
						break;
					}
					if (mask_3) {
						for (int k = 0; k < 1000; k++) {
							for (int i = 0; i < 276; i++) {
								if ((navigator[i] & mask_3) != 0) {

									if (r_vector3[k].test(i + 443)) {

										for (int j = 0; j < 276; j++) {
											if ((navigator[i] ^ mask_3) == 0) {
												if (val != 0) {
													if (r_vector3[k].test(719)) {
														r_vector3[k][719] = 0;
													}
													else {
														r_vector3[k][719] = 1;
													}
												}
												break;
											}

											if (navigator[j] == (navigator[i] ^ mask_3)) {
												if (val != 0) {
													if (r_vector3[k].test(j + 443)) {
														r_vector3[k][j + 443] = 0;
													}
													else {
														r_vector3[k][j + 443] = 1;
													}
												}

												break;
											}
										}
										r_vector3[k][i + 443] = 0;
									}//if
								}
							}

						}
					}//if(mask_3)
				}



				
				final_size_1 = 19;
				for (int p = 0; p < 19; p++) {
					if ((pos_1 & (1 << p)) != 0) {
						final_size_1--;
					}
				}
				final_size_2 = 22;
				for (int p = 0; p < 22; p++) {
					if ((pos_2 & (1 << p)) != 0) {
						final_size_2--;
					}
				}
				final_size_3 = 23;
				for (int p = 0; p < 23; p++) {
					if ((pos_3 & (1 << p)) != 0) {
						final_size_3--;
					}
				}

				
				final_size_1 = (final_size_1) * (final_size_1 - 1) / 2 + final_size_1;
				final_size_2 = (final_size_2) * (final_size_2 - 1) / 2 + final_size_2;
				final_size_3 = (final_size_3) * (final_size_3 - 1) / 2 + final_size_3;
				unsigned int final_size = final_size_1 + final_size_2 + final_size_3;
				
				//1111

				for (int i = 0; i < 1000; i++) {
				
					for (int j = 189; j >= 0; j--) {
						if ((navigator[j] & pos_1) != 0) {
							for (int k = j; k < 189; k++) {
								r_vector1[i][k] = r_vector1[i][k + 1];
								r_vector1[i][k + 1] = 0;
							}
						}

					}
					r_vector1[i][final_size] = r_vector1[i][719];
					r_vector1[i][719] = 0;
				}
				////22222
				for (int i = 0; i < 1000; i++) {
				
					for (int j = 252; j >= 0; j--) {
						if ((navigator[j] & pos_2) != 0) {
							for (int k = j; k < 252; k++) {
								r_vector2[i][k + 190] = r_vector2[i][k + 1 + 190];
								r_vector2[i][k + 1 + 190] = 0;
							}
						}

					}
				}

				///3333
				for (int i = 0; i < 1000; i++) {
					for (int j = 275; j >= 0; j--) {
						if ((navigator[j] & pos_3) != 0) {
							for (int k = j; k < 275; k++) {
								r_vector3[i][k + 443] = r_vector3[i][k + 1 + 443];
								r_vector3[i][k + 1 + 443] = 0;
							}
						}

					}
				}

				
				////22222

				for (int i = 0; i < 1000; i++) {
					if (final_size_1 != 190) {
						for (int j = final_size_1; j < (final_size_1 + final_size_2); j++) {
							r_vector2[i][j] = r_vector2[i][j + (190 - final_size_1)];
							r_vector2[i][j + (190 - final_size_1)] = 0;

						}
					}
					r_vector2[i][final_size] = r_vector2[i][719];
					r_vector2[i][719] = 0;
				}


				/////33333

				for (int i = 0; i < 1000; i++) {
					if ((final_size_1 != 190) || (final_size_2 != 253)) {
						for (int j = final_size_1 + final_size_2; j < final_size; j++) {
							r_vector3[i][j] = r_vector3[i][j + ((443 - (final_size_2 + final_size_1)))];
							r_vector3[i][j + ((443 - (final_size_2 + final_size_1)))] = 0;

						}
					}
					r_vector3[i][final_size] = r_vector3[i][719];
					r_vector3[i][719] = 0;
				}

				unsigned int start_time = clock();
				
				for (key = 0; key <= 0x1ffff; key++) {//0x1ffff

					//cout << key << "*\n";
					it1 = r_vector1.begin();
					it2 = r_vector2.begin();
					it3 = r_vector3.begin();
					
					for (int i = 0; i < matrix.size(); i++)
					{
						matrix[i].reset();
					}

					ind = true;
					keytmp = key;
					
					for (int k = 0; k < n; k++) {
						matrix[k][final_size] = gamma[k];
					}



					
					for (int j = 0; j < n; j++) {
						unsigned int ctrl = (((keytmp >> 15) & 1) << 2) | (((keytmp >> 6) & 1) << 1) | (((keytmp >> 1) & 1) << 0);
						if (((0xE8 >> ctrl) & 1) == ((keytmp >> 15) & 1))
						{
							it1++;
						}
						if (((0xE8 >> ctrl) & 1) == ((keytmp >> 6) & 1))
						{
							it2++;
						}
						if (((0xE8 >> ctrl) & 1) == ((keytmp >> 1) & 1))
						{
							it3++;
						}
						matrix[j] ^= *it1;
						matrix[j] ^= *it2;
						matrix[j] ^= *it3;
						keytmp = ((keytmp << 1) | (((keytmp >> 16) ^ (keytmp >> 13) ^ (keytmp >> 12) ^ (keytmp >> 8)) & 1)) & 0x1ffff;
					}


					


					for (int i = 0; i < final_size; i++)
					{
						pos = i + 1;
						if (!matrix[i].test(i)) {
							for (int j = i + 1; j < n; j++) {
								if (matrix[j].test(i)) {
									pos = j + 1;
									matrix[i] ^= matrix[j];
									matrix[j] ^= matrix[i];
									break;
								}
							}
						}
						for (int j = pos; j < n; j++) {
							if (matrix[j].test(i)) {
								matrix[j] ^= matrix[i];

							}
						}
					}
					ind = true;

					for (int i = 0; i < final_size; i++) {
						if (!matrix[i].test(i))
						{
							ind = false;
							break;
						}
					}

					if (ind) {
						for (int i = final_size; i < n; i++) {
							if (matrix[i].any()) {
								//std::cout << "========" << i << "========";
								ind = false;
								break;
							}
						}
					}

					if (ind) {

						for (int i = final_size - 1; i >= 0; i--) {
							if (matrix[i].test(i)) {
								for (int j = i - 1; j >= 0; j--) {
									if (matrix[j].test(i)) {
										matrix[j] ^= matrix[i];

									}
								}
							}
						}


						it = matrix.begin();
						//////////////REG 11111111
						int point = 0;
						count = 0;
						pos = 0;
						reg_1 = 0;
						for (int i = 0; i < 190; i++) {
							if (!(navigator[i] & pos_1)) {
								count = 0;
								for (int j = 0; j < 19; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {                          
									reg_1 = (reg_1 | (*it)[final_size]);
									reg_1 = (reg_1 << 1);
								}
								it++;
							}
							else {
								count = 0;
								for (int j = 0; j < 19; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {                         
									reg_1 = (reg_1 | (val_1 >> point));
									reg_1 = (reg_1 << 1);
									point++;
								}




							}
						}


						//////////////////REG 22222
						point = 0;
						count = 0;
						pos = 0;
						reg_2 = 0;
						for (int i = 0; i < 253; i++) {
							if (!(navigator[i] & pos_2)) {
								count = 0;
								for (int j = 0; j < 22; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {         
									reg_2 = (reg_2 | (*it)[final_size]);
									reg_2 = (reg_2 << 1);
								}
								it++;
							}
							else {
								count = 0;
								for (int j = 0; j < 22; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {          
									reg_2 = (reg_2 | (val_2 >> point));
									reg_2 = (reg_2 << 1);
									point++;
								}




							}
						}


						////////REG 33333333333
						point = 0;
						count = 0;
						pos = 0;
						reg_3 = 0;
						for (int i = 0; i < 276; i++) {
							if (!(navigator[i] & pos_3)) {
								count = 0;
								for (int j = 0; j < 23; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {                 
									reg_3 = (reg_3 | (*it)[final_size]);
									reg_3 = (reg_3 << 1);
								}
								it++;
							}
							else {
								count = 0;
								for (int j = 0; j < 23; j++) {
									if ((navigator[i] >> j) == 0) {
										break;
									}
									if (((navigator[i] >> j) & 1) != 0) {
										count++;
									}
								}
								if (count == 1) {                      
									reg_3 = (reg_3 | (val_3 >> point));
									reg_3 = (reg_3 << 1);
									point++;
								}




							}
						}

						unsigned int temp_reg_1 = 0;
						unsigned int temp_reg_2 = 0;
						unsigned int temp_reg_3 = 0;
						for (int i = 0; i < 32; i++) {
							temp_reg_1 = (temp_reg_1 << 1);
							temp_reg_1 = (temp_reg_1 | ((reg_1 >> i) & 1));
							temp_reg_2 = (temp_reg_2 << 1);
							temp_reg_2 = (temp_reg_2 | ((reg_2 >> i) & 1));
							temp_reg_3 = (temp_reg_3 << 1);
							temp_reg_3 = (temp_reg_3 | ((reg_3 >> i) & 1));
						}
						temp_reg_1 = (temp_reg_1 >> 12);
						temp_reg_2 = (temp_reg_2 >> 9);
						temp_reg_3 = (temp_reg_3 >> 8);
				

						reg_1 = temp_reg_1;
						reg_2 = temp_reg_2;
						reg_3 = temp_reg_3;
						reg_4 = key;
						cout << "reg_1: " << hex << reg_1 << endl;
						cout << "reg_2: " << hex << reg_2 << endl;
						cout << "reg_3: " << hex << reg_3 << endl;
						cout << "reg_4: " << hex << reg_4 << endl;

						for (int i = 0; i < 250; i++) {
							reg_1 = (reg_1 >> 1) | ((((((reg_1 >> 0) ^ (reg_1 >> 18) ^ (reg_1 >> 17) ^ (reg_1 >> 14)) & 1)) & 0x7ffff) << 18);
							reg_2 = (reg_2 >> 1) | ((((((reg_2 >> 0) ^ (reg_2 >> 21) ^ (reg_2 >> 17) ^ (reg_2 >> 13)) & 1)) & 0x3fffff) << 21);
							reg_3 = (reg_3 >> 1) | ((((((reg_3 >> 0) ^ (reg_3 >> 22) ^ (reg_3 >> 19) ^ (reg_3 >> 18)) & 1)) & 0x7fffff) << 22);
							reg_4 = (reg_4 >> 1) | ((((((reg_4 >> 0) ^ (reg_4 >> 14) ^ (reg_4 >> 13) ^ (reg_4 >> 9)) & 1)) & 0x1ffff) << 16);

						}
						
						ifstream key_system_r1_input("key_system_r1.txt");
						ifstream key_system_r2_input("key_system_r2.txt");
						ifstream key_system_r3_input("key_system_r3.txt");
						ifstream key_system_r4_input("key_system_r4.txt");
						if (!key_system_r1_input.is_open() || !key_system_r2_input.is_open() || !key_system_r3_input.is_open() || !key_system_r4_input.is_open())
						{
							cout << "Some of files did not open!\n";

							return 1;
						}
						vector<bitset<65>> vectorkey(78);
						for (int i = 0; i < 18; i++) {
							if (i == 0) {
								key_system_r1_input >> val_1;
								key_system_r1_input >> val_2;
							}
							key_system_r1_input >> val_1;
							key_system_r1_input >> val_2;
							for (int j = 0; j < 32; j++) {
								vectorkey[i][j] = (val_1 >> j) & 1;
							}
							for (int j = 32; j < 64; j++) {
								vectorkey[i][j] = (val_2 >> (j - 32)) & 1;
							}

						}
						for (int i = 0; i < 21; i++) {
							if (i == 0) {
								key_system_r2_input >> val_1;
								key_system_r2_input >> val_2;
							}
							key_system_r2_input >> val_1;
							key_system_r2_input >> val_2;
							for (int j = 0; j < 32; j++) {
								vectorkey[i + 18][j] = (val_1 >> j) & 1;
							}
							for (int j = 32; j < 64; j++) {
								vectorkey[i + 18][j] = (val_2 >> (j - 32)) & 1;
							}
						}
						for (int i = 0; i < 22; i++) {
							if (i == 0) {
								key_system_r3_input >> val_1;
								key_system_r3_input >> val_2;
							}
							key_system_r3_input >> val_1;
							key_system_r3_input >> val_2;

							for (int j = 0; j < 32; j++) {
								vectorkey[i + 39][j] = (val_1 >> j) & 1;
							}
							for (int j = 32; j < 64; j++) {
								vectorkey[i + 39][j] = (val_2 >> (j - 32)) & 1;
							}

						}
						for (int i = 0; i < 16; i++) {
							if (i == 0) {
								key_system_r4_input >> val_1;
								key_system_r4_input >> val_2;
							}
							key_system_r4_input >> val_1;
							key_system_r4_input >> val_2;

							for (int j = 0; j < 32; j++) {
								vectorkey[i + 61][j] = (val_1 >> j) & 1;
							}
							for (int j = 32; j < 64; j++) {
								vectorkey[i + 61][j] = (val_2 >> (j - 32)) & 1;
							}

						}
						reg_1 = (reg_1 >> 1);
						for (int i = 0; i < 18; i++) {
							vectorkey[i][64] = (reg_1 & 1);
							reg_1 = (reg_1 >> 1);
						}
						reg_2 = (reg_2 >> 1);
						for (int i = 0; i < 21; i++) {
							vectorkey[i + 18][64] = (reg_2 & 1);
							reg_2 = (reg_2 >> 1);
						}
						reg_3 = (reg_3 >> 1);
						for (int i = 0; i < 22; i++) {
							vectorkey[i + 39][64] = (reg_3 & 1);
							reg_3 = (reg_3 >> 1);
						}
						reg_4 = (reg_4 >> 1);
						for (int i = 0; i < 16; i++) {
							vectorkey[i + 61][64] = (reg_4 & 1);
							reg_4 = (reg_4 >> 1);
						}



						for (int i = 0; i < 64; i++)
						{
							pos = i + 1;
							if (!vectorkey[i].test(i)) {
								for (int j = i + 1; j < 78; j++) {
									if (vectorkey[j].test(i)) {
										pos = j + 1;
										vectorkey[i] ^= vectorkey[j];
										vectorkey[j] ^= vectorkey[i];
										break;
									}
								}
							}
							for (int j = pos; j < 78; j++) {
								if (vectorkey[j].test(i)) {
									vectorkey[j] ^= vectorkey[i];

								}
							}
						}

						for (int i = 63; i >= 0; i--) {
							if (vectorkey[i].test(i)) {
								for (int j = i - 1; j >= 0; j--) {
									if (vectorkey[j].test(i)) {
										vectorkey[j] ^= vectorkey[i];

									}
								}
							}
						}
						key_system_r1_input.close();
						key_system_r2_input.close();
						key_system_r3_input.close();
						key_system_r4_input.close();
						unsigned __int64 final_key = 0;
						final_key |= (vectorkey[31][64] & 1);
						for (int i = 30; i >= 0; i--) {
							final_key = final_key << 1;
							final_key |= (vectorkey[i][64] & 1);
						}
						for (int i = 63; i >= 32; i--) {
							final_key = final_key << 1;
							final_key |= (vectorkey[i][64] & 1);
						}
						printf("Key: %.4X", final_key >> 32);
						printf("%.4X\n", final_key);
						return 0;
					}
				}
			}//for
		}//for
	}//for

	return 1;
}
