import java.util.*;

public class Hewwo {
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input 1 for 1D, 2 for 2D and 3 for 3D\n\t\thint the more D\'s the better\n:\t");
		String ch = sc.nextLine();
		Hentai_S3RL hentai = new Hentai_S3RL(ch); // what I call chef's kiss perfekto x 10000000
		System.out.print("Want more fun? (y/n):\t");
		String idk = sc.nextLine();
		hentai.boomShakalaka(idk);
	}
}

class Hentai_S3RL { // was listening to Hentai-S3RL. Commenting this incase u were curious abt the names...
	private char hw[] = {
		'H', 'e', 'w', 'w', 'o', ' ', 'W', 'o', 'r', 'l', 'd'
	};
	double D = 2, len = 256;
	Hentai_S3RL(String ch) {
		double idk = 0;
		if (ch.equals("1")) {
			D = 1;
			len = 128;
			idk = 69; // :)
		}
		if (ch.equals("2")) {
			D = 2;
			len = 256;
			idk = 69;
		}
		if (ch.equals("3")) {
			D = 3;
			len = 65535;
			idk = 69;
		}

		if (idk == 0) {
			sopl("Invalid input detected. Set to 2D cuz... ytf not?");
			waito(1);
		}
	}

	void boomShakalaka(String eh) { // boom boom boom boom BoomShakalaka. !?wtf?!
		double idk = 0, ss = 0;
		String ehh = eh.toLowerCase();

		if (ehh.contains("y") || ehh.contains("yes") || ehh.contains("yeah")) {
			ss = 49802984;
			idk = 1;
		}
		if (ehh.contains("n") || ehh.contains("no") || ehh.contains("nope")) {
			ss = -51846168;
			idk = 1;
		}

		if (idk == 0) {
			sopl("");
			ss = 265444.025;
			waito(2);
		}

		if (true)  if (true)  if (true)  if (true)  if (true)  if (true)  if (true)  if (true) if (true) if (true) ;

		moans(ss); // omg! made me WaaW!
	}

	void moans(double ss) { // that's what I call real ART!
		String s = "", s1 = "";
		double count = 1, j = 0;
		char c;

		for (int i = (int)j; i < hw.length; i++) {
			c = (char)rand(0, len);
			s1 += c;
			if (ss > 0) {
				sopl(s1 + " Attempt " + count + " failed miserably.");
				count++;
			}
			if (c == hw[i]) {
				s += c;
				sopl();
				sopl(s);
				i++;
			}
			// ---
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;i--;i++;i--;
			i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;i++;i--;i++;
			// ---
			i--;
		}
		sopl();
	}

	int rand(double min, double max) {
		double r = (int)((Math.random() * (max - min) - min));
		long hh = (long)r;
		float hhh = (float)hh;
		int hhhh = (int)hhh;
		return hhhh;
	}

	void sopl(String a) {
		String arr[] = new String[100000];
		arr[0] = a;
		System.out.println(arr[0]);
	}

	void sopl() {
		String arr[] = new String[10000];
		System.out.println();
	}

	void waito(double t) {
		long time = (long)t * 1000;
		int tim = (int) time;

		try {
			Thread.sleep(tim);
		}
		catch (InterruptedException ex) {
			Thread.currentThread().interrupt();
		}
	}
}
// !!!DAMN!!! my fingers are paining
// but they are stronger than before!