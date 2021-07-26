#include "annoyer.h"

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
	int8_t ec = 0, ecc = 0;

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
			prl("Version 1");
			prl("This crap is obviously made by a depressed, lonely, mentally retarded and stupid 15 y/o kid");
			prl("Umm... about this calculator--->");
			prl("\tThis was developed over a period of 1 damn month.");
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
				help(); // good lord it's 'K'lean af 😉
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
				helpc(); // リヴァイ　アッケルマン　move \'KLEANLINESS'/
				// okay i'm just insulting him... sad lyfe 😥😢
			}
			else if (validex(ip))
			{
				prl("---------------------------------------");
				pr("Result:\t");
				prl(expr(ip));
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

	WAIT(450);
	prl("Matane!");
	WAIT(350);
	prl("\t\t\t\t\tor sayonara! I guess?");
}