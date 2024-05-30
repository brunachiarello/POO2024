/**
 * Compara arquivos, palavra por palavra.
 * 
 * @author Roland Teodorowitsch
 * @version 12 abr. 2017
 */

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class jwdiff {
    final static double VERSION = 1.1;
    
    public static void usage() {
        System.err.printf("jwdiff - Versão %.1f\n",VERSION);
        System.err.printf("Usage:\n   jwdiff [--brief] <file1> <file2>\n\n");
        
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        boolean verbose = true;
        int files_index = 0;
        if (args.length > 0 && args[0].equals("--brief")) {
           files_index = 1;
           verbose = false;
        }
        if (args.length-files_index != 2) {
            usage();
            System.exit(1);
        }
        Scanner f1 = new Scanner(new File(args[files_index]));
        Scanner f2 = new Scanner(new File(args[files_index+1]));
        while (f1.hasNext()) {
            String w1 = f1.next();
            if (!f2.hasNext()) {
               if ( verbose ) System.out.printf("[ONDE DEVERIA APARECER] %s [APARECEU]\n", w1);
               System.exit(1);
            }
            String w2 = f2.next();
            if (!w1.equals(w2)) {
               if ( verbose ) System.out.printf("[ONDE DEVERIA APARECER] %s [APARECEU] %s\n", w1, w2);
               System.exit(1);
            }
        }
        if (f2.hasNext()) {
           if ( verbose ) System.out.printf("[ONDE DEVERIA APARECER] [APARECEU]%s\n", f2.next());
           System.exit(1);
        }
        f1.close();
        f2.close();
        System.exit(0);
    }
    
}
