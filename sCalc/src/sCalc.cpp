#include "fileIO.h"

void unspc(str& inp)
{
	unsigned int i = 0;
	char c;
	str r = "";
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
	str ip = "", m = "(cmd)", pm = "==>   ";
	str fileName = "sCalc-set.baka";

	bool RUN = true, hap = false, hapc = false;
	// hap -> help annoyed prompt?, hapc -> help annoyed prompt calc
	// my existence makes no sense
	char ec = 0, ecc = 0, hc = 0, hcc = 0;

	prl("This is a useless cli calculator");
	prl("Depressing news, its neither space nor case sensitive           \'/h\' for help, \'/qq\' one of the thousand ways to quit");
	prl("If you face any health issues and think its because of this then delete this crap from your drive.");
	
	if (readFile(fileName))
	{
		pr("\n");
		m = "(calc)";
		pm = "==>  ";
	}
	
	while (RUN)
	{
		pr(m);
		pr(pm);

		std::getline(std::cin, ip);

		unspc(ip); // i missed it... 😭🤬🤬🤪😵🥴 reminds me of some stupid anime character...

		std::transform(ip.begin(), ip.end(), ip.begin(), ::tolower);

		if (ip == "")
		{
			// watch anime
		}
		else if (ip == "/abt" || ip == "/about")
		{
			prl("Version 2.0");
			prl("This crap is obviously made by a depressed, lonely, mentally retarded and stupid 15 y/o kid");
			prl("Umm... about this calculator--->");
			prl("\tIt dosen't support brackets of any form.");
			prl("It is neither case nor space sensitive(literally)");
			prl("\tMicrosoft calculator is better (browsers are also better or you can try print(<expression>) in a python file). Don't even try this crap cuz it just not worth it.");
			prl("");
		}
		else if (ip == "/qq")
		{
			break;
		}
		else if (ip == "/set-cs-1" || ip == "/set-cs-true" || ip == "/set-cs-69")
			writeFile(fileName, 69);
		else if (ip == "/set-cs-0" || ip == "/set-cs-false")
			writeFile(fileName, 0);
		else if (m == "(cmd)")
		{
			if (ip == "/h" || ip == "/help")
			{
				prl(help[hc]);
				hc++;
				if (hc > 3)
					hc--;
				
			}
			else if (ip == "/s" || ip == "/str" || ip == "/start")
			{
				m = "(calc)";
				pm = "==>  ";
			}
			else if (ip == "/ust")
			{
				prl(selft[0]); // ah... it's so 'K'lean 😊
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
					pr((int)ec);
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
					break;
				ec++;
			}
		}
		else if (m == "(calc)")
		{
			if (ip == "/ust")
			{
				prl(selft[1]); // 'K'LEAN 👌👌
			}
			else if (ip == "/q")
			{
				m = "(cmd)";
				pm = "==>   ";
			}
			else if (ip == "/h" || ip == "/help")
			{
				// i hope I never existed 😢😥😭
				prl(helpc[hcc]);
				hcc++;
				if (hcc > 3)
					hcc--;
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
					pr((int)ecc);
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
					break;
				ecc++;
			}
		}
	}

	prl("Matane!");
	WAIT(450);
	prl("\t\t\t\t\tor sayonara! I guess?");
	WAIT(350);
}