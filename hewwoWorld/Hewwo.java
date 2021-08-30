// to run u need jvm installed and added to paf
// cmd to run --> java -Xmx100g Hewwo.java   ...yes I mean WTAF!??!
// yes you need 12gb ram ☺, i guess? you can increase it
// javac gives in comment... (48) Yes java SUCKS
//

import java.util.*;
import java.awt.*;
import java.net.*;
// somethin s comin up

public class Hewwo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Better b = new Better();
        System.out.print("Input 1 for 1D, 2 for 2D and 3 for 3D");
        b.ssop("\n\t\thint the more D's the better\n:\t");
        String ch = scanner.nextLine();
        Hentai_S3RL hentai = new Hentai_S3RL(ch); // what I call chef's kiss perfekto x 10000000
        b.ssop("Want more fun? (y/n):\t");
        String idk = scanner.nextLine();
        hentai.boomShakalaka(idk);
        scanner.close();
    }
}

class Hentai_S3RL { // was listening to Hentai-S3RL. Commenting this incase u were curious abt the names...
    static int imb = Integer.MAX_VALUE;  // this doesn't work then use this ---> Integer.MAX_VALUE / 9
    private char h = 'H', e = 'e', w1 = 'w', w2 = 'w', o = 'o', spc = ' ', w = 'W', o2 = 'o', r = 'r', l = 'l', d = 'd';

    private char H[]   = new char[imb];
    private char E[]   = new char[imb];
    private char W1[]  = new char[imb];
    private char W2[]  = new char[imb];
    private char O[]   = new char[imb];
    private char SPC[] = new char[imb];
    private char W3[]  = new char[imb];
    private char O2[]  = new char[imb];
    private char R[]   = new char[imb];
    private char L[]   = new char[imb];
    private char D_[]  = new char[imb];

    private char hw[] = new char[imb];


    double D = 2, len = 256;

    Better itsGood;

    Hentai_S3RL(String ch) {
        javaSUCKS();

        double idk = 0;
        while (ch.equals("1")) { // if statement but while loop 😏(●'◡'●)
            D = 1;
            len = 128;
            idk = 69; // :)
            break;
        }
        while (ch.equals("2")) {
            D = 2;
            len = 256;
            idk = 69;
            break;
        }
        while (ch.equals("3")) {
            D = 3;
            len = 65535;
            idk = 69;
            break;
        }

        while (idk == 0) {
            sopl("Invalid input detected. Set to 2D cuz... ytf not?");
            waito(1);
            break;
        }
    }

    void javaSUCKS() {
        Arrays.fill(H, h);
        Arrays.fill(E, e);
        Arrays.fill(W1, w1);
        Arrays.fill(W2, w2);
        Arrays.fill(O, o);
        Arrays.fill(SPC, spc);
        Arrays.fill(W3, w);
        Arrays.fill(O2, o2);
        Arrays.fill(R, r);
        Arrays.fill(L, l);
        Arrays.fill(D_, d);
        // heh 😊

        hw[0] = H[rand(0, imb - 1)];
        hw[1] = E[rand(0, imb - 1)];
        hw[2] = W1[rand(0, imb - 1)];
        hw[3] = W2[rand(0, imb - 1)];
        hw[4] = O[rand(0, imb - 1)];
        hw[5] = SPC[rand(0, imb - 1)];
        hw[6] = W3[rand(0, imb - 1)];
        hw[7] = O2[rand(0, imb - 1)];
        hw[8] = R[rand(0, imb - 1)];
        hw[9] = L[rand(0, imb - 1)];
        hw[10] =D_[rand(0, imb - 1)];
    }

    void boomShakalaka(String eh) { // boom boom boom boom BoomShakalaka. !?wtf?!
        double idk = 0, ss = 0;
        String ehh = eh.toLowerCase();

        while (ehh.contains("y") || ehh.contains("yes") || ehh.contains("yeah")) {
            ss = 49802984;
            idk = 1;
            break;
        }
        while (ehh.contains("n") || ehh.contains("no") || ehh.contains("nope")) {
            ss = -51846168;
            idk = 1;
            break;
        }

        while (idk == 0) {
            sopl("");
            ss = 265444.025;
            waito(2);
            break;
        }

        thisMakesItMoreEfficient();

        itsGood = new Better(D, ss);

        moans(ss); // omg! made me WaaW!
    }

    void moans(double ss) { // that's what I call real ART!
        String s = "", s1 = "";
        double count = 1, j = 0;
        char c;

        for (int i = (int)j; i < 11; i++) {
            c = (char)rand(0, len);
            s1 += c;
            while (ss > 0) {
                sopl(s1 + " Attempt " + count + " failed miserably.");
                count++;
                break;
            }
            while (c == hw[i]) {
                s += c;
                sopl();
                sopl(s);
                i++;
                break;
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
            // --- :)
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

    static void sopl(String a) {
        String arr[] = new String[imb];
        Arrays.fill(arr, a);
        System.out.println(arr[imb - 1]);
    }

    static void sopl() {
        String arr[] = new String[imb];
        Arrays.fill(arr, "");
        System.out.println(arr[imb - 1]);
    }

    static void waito(double time) {
        double tim = time * 1000;
        float ti = (float) tim;
        int idk = (int) ti;
        long t = idk;

        try {
            Thread.sleep(t);
        }
        catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }

    void thisMakesItMoreEfficient() {
        while (true) {
            while (true) {
                while (true) {
                    while (true) {
                        while (true) {
                            while (true) {
                                while (true) {
                                    while (true) {
                                        while (true) {
                                            while (true) {
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
    }
}

class Better {
    double sD = 1, sCh = 0;

    Better() {}

    Better(double D, double ch) {
        if (ch > 0) {
            if (D == 1)
                sD = 1;
            if (D == 2)
                sD = 2;
            if (D == 3)
                sD = 3;
            sCh = 1;
        }
        if (ch < 0) {
            if (D == 1)
                sD = 1;
            if (D == 2)
                sD = 2;
            if (D == 3)
                sD = 3;
            sCh = -9110;
        }
        ohhYeah();
    }
    void ohhYeah() {
        if (sCh > 0) {
            if (sD == 1)
                ssopl("Ohhh! You seem quite interesting...");
            if (sD == 2) {
                ssopl("You are really seducing me as hell!");
                Hentai_S3RL.waito(1);
                Hentai_S3RL.sopl();
                ssopl(" I probably can't stop myself...");
                Hentai_S3RL.waito(1);
                Hentai_S3RL.sopl();
            }
            if (sD == 3) {
                ssopl("Ohhh God! You've really turned me on and got me hot as f*ck!");
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(3);
                ssopl("You seductive human!...");
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(0.3);
                Hentai_S3RL.sopl("<breathes>");
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(2);
                ssopl("I can't wait anymore! Nor will I!");
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(2);
                ssopl("I'll just do it.");
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(2);
                ssopl("Don't worry it'll be hard and long!");
                Hentai_S3RL.sopl();
                Hentai_S3RL.sopl();
                Hentai_S3RL.waito(3);
            }
        }
        if (sCh < 0) {
            if (sD == 1)
                ssopl("Hmm... You're boooring");
            if (sD == 2)
                ssopl("Damn! That's some good moves to turn me on");
            if (sD == 3){
                ssopl("Ohh! You did arouse me but just a little...");
                Hentai_S3RL.waito(1);
            }
        }
    }

    void ssopl(String str) {
        int len = 0;
        for (; len < str.length(); len++) {
            System.out.print(str.charAt(len) + "");
            Hentai_S3RL.waito(0.1);
        }
        Hentai_S3RL.sopl();
    }

    void ssop(String str) {
        int len = 0;
        for (; len < str.length(); len++) {
            System.out.print(str.charAt(len) + "");
            Hentai_S3RL.waito(0.1);
        }
    }
}
// !!!DAMN!!! my fingers are paining
// but they are stronger than before!
