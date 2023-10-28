#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: rev.exe input_file output_file\n");
        return -1;
    }

    int ret = 0;
    do
    {
        struct stat st;
        if (stat(argv[1], &st) != 0)
        {
            fprintf(stderr, "stat\n");
            ret = -2;
            break;
        }

        std::string str;
        str.reserve(st.st_size);

        FILE *fin = fopen(argv[1], "rb");
        if (!fin)
        {
            fprintf(stderr, "!fin\n");
            ret = -3;
            break;
        }

        char buf[1024];
        for (;;)
        {
            size_t cb = fread(buf, 1, sizeof(buf), fin);
            if (cb == 0)
                break;

            str.append(buf, cb);
        }

        if (ferror(fin))
        {
            fclose(fin);
            fprintf(stderr, "ferror\n");
            ret = -4;
            break;
        }

        fclose(fin);

        std::reverse(str.begin(), str.end());

        FILE *fout = fopen(argv[2], "wb");
        if (!fout)
        {
            fprintf(stderr, "!fout\n");
            ret = -5;
            break;
        }

        if (!fwrite(str.c_str(), str.size(), 1, fout))
        {
            fprintf(stderr, "!fwrite\n");
            ret = -6;
        }

        fclose(fout);
    } while (0);

    return ret;
}
