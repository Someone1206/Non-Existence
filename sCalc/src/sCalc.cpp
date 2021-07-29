#include "annoyer.h";

void unspc(string& inp)
{
	short i = 0;
	char c;
	string r = "";
	for (i = 0; i < inp.length(); i++)
	{
		c = inp.at(i);
		if (!isspace(c))
		{
			r += c;
		}
	}
	inp = r;
}

int main()
{
	bool first = true;
	int8_t ec = 0, ecc = 0, hc = 0, hcc = 0;

	while (RUN)
	{
		if (first)
		{
			prl("This is a useless cli calculator");
			prl("Depressing news, its neither space nor case sensitive           \'/h\' for help, \'/qq\' one of the thousand ways to quit");
			prl("If you face any health issues and think its because of this then delete this crap from your drive.");
			first = false;
		}

		pr(m);
		pr(pm);

		getline(cin, ip);

		unspc(ip); // i missed it... 😭🤬🤬🤪😵🥴 reminds me of some stupid anime character...

		transform(ip.begin(), ip.end(), ip.begin(), ::tolower);

		if (ip == "")
		{
			continue;
		}
		else if (ip == "/abt" || ip == "/about")
		{
			prl("Version 1.1.0");
			prl("This crap is obviously made by a depressed, lonely, mentally retarded and stupid 15 y/o kid");
			prl("Umm... about this calculator--->");
			prl("\tIt dosen't support brackets of any form.");
			prl("\tMicrosoft calculator is better (browsers are also better or you can try print(<expression>) in a python file). Don't even try this crap cuz it just not worth it.");
			prl("");
			continue;
		}
		else if (ip == "/qq")
		{
			RUN = false;
			break;
		}

		else if (m == "(cmd)")
		{
			if (ip == "/h" || ip == "/help")
			{
				// how to spoil things 😭
				if (hc < 2)
					prl(help[0]);
				else if (hc < 3)
					prl(help[1]);
				else if (hc < 5)
					prl(help[2]);
				else if (hc < 7)
					prl(help[3]);
				else
				{
					prl(help[4]);
					if (hc == 7)
					{
						prl("   Its always good to help so I won\'t quit :|");
						hc++;
					}
					continue;
				}
				hc++;
			}
			else if (ip == "/s" || ip == "/str" || ip == "/start")
			{
				m = "(calc)";
				pm = "==>  ";
			}
			else if (ip == "/ust")
			{
				selft(1); // ah... it's so 'K'lean 😊
			}
			else
			{
				if (ec < 2)
				{
					prl("Error-_-.");
				}
				else if (ec < 4)
				{
					pr("Wtf!? You\'ve already made ");
					pr(static_cast<int16_t>(ec));
					prl(" errors");
				}
				else if (ec < 6)
				{
					prl("Yamero! Baka! You've got my processor on fire");
				}
				else if (ec < 8)
				{
					prl("Kisama wa baaaka ga?");

					if (ec == 6)
						prl("\t\t\tI can\'t type japanese in windows cmd");
				}
				else if (ec < 10)
				{
					prl("Arrrgh. Wut?!?!");
				}
				else
				{
					RUN = false;
					break;
				}
				ec++;
			}
		}
		else if (m == "(calc)")
		{
			if (ip == "/ust")
			{
				selft(2); // 'K'LEAN 👌👌
			}
			else if (ip == "/q")
			{
				m = "(cmd)";
				pm = "==>   ";
			}
			else if (ip == "/h" || ip == "/help")
			{
				// i hate myself, hope I never existed 😢😥😭
				if (hcc < 1)
					prl(helpc[0]);
				else if (hcc < 2)
					prl(helpc[1]);
				else if (hcc < 3)
					prl(helpc[2]);
				else if (hcc < 5)
					prl(helpc[3]);
				else
				{
					prl(helpc[4]);
					if (hcc == 5)
					{
						prl("   Its always good to help so I won\'t quit :)");
						hcc++;
					}
					continue;
				}
				hcc++;
			}
			else if (validex(ip))
			{
				prl("---------------------------------------");
				pr("Result:\t");
				prl(expr(ip)); // リヴァイ　アッケルマン　move \'KLEANLINESS'/
				// okay i'm just insulting him... sad lyfe 😥😢    ...heh eh 😭😭
				prl("---------------------------------------");
			}
			else
			{
				if (ecc < 2)
				{
					prl("Error-_-.");
				}
				else if (ecc < 6)
				{
					pr("Wtf!? You\'ve already made ");
					pr(static_cast<int16_t>(ecc));
					prl(" errors");
				}
				else if (ecc < 8)
				{
					prl("Yamero! Baka! You've got my processor on fire");
				}
				else if (ecc < 10)
				{
					prl("Kisama wa baaaka ga?");
				}
				else
				{
					RUN = false;
					break;
				}
				ecc++;
			}
		}
	}


	prl("Matane!");
	WAIT(450);
	prl("\t\t\t\t\tor sayonara! I guess?");
	WAIT(350);
}