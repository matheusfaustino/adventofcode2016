#include "adventofcode.h"
#include <openssl/md5.h>

void md5_hash(char *string, char *hash)
{
        int i;
        char unsigned md5[MD5_DIGEST_LENGTH];

        MD5((const unsigned char *)string, strlen(string), md5);

        for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
                sprintf(hash + 2*i, "%02x", md5[i]);
        }
}

int main(int argc, char const *argv[])
{
        size_t len = 0;
        ssize_t read;
        int answer = 0;
        char *line = NULL;
        char *secret_key = NULL;
        char *substring = NULL;
        char hash[2*MD5_DIGEST_LENGTH+1] = "";
        FILE *input = handle_file_by_arg(argc, argv);

        while ((read = getline(&line, &len, input)) != -1) {

                /* cleans \n character */
                line[strcspn(line, "\n")] = 0;

                do {
                        // alloc and set new string
                        asprintf(&secret_key, "%s%d", line, ++answer);
                        md5_hash(secret_key, hash);
                        substring = strstr(hash, "00000");
                } while (!(substring != NULL && (substring-hash) == 0));

                printf("First: %d\n", answer);

                answer = 0;
                do {
                        asprintf(&secret_key, "%s%d", line, ++answer);
                        md5_hash(secret_key, hash);
                        substring = strstr(hash, "000000");
                } while (!(substring != NULL && (substring-hash) == 0));

                printf("Second: %d\n", answer);

                free(secret_key);
        }

        return 0;
}
