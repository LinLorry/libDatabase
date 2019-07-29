#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

#include <Security/Security.h>

namespace Security
{
    class DatabaseSecurityHeader 
    {
    public:
        constexpr static const char* ALGORITHM = "RSA";
    private:      
        BIO *public_key;
        BIO *private_key;
        int location = 0;
        int size;

    public:
        static byte_string & generateHeader(const byte_string &password);

    public:
        DatabaseSecurityHeader(const byte_string &headerBytes,
                            const byte_string &passwordMd5);
        
        const byte_string & updatePassword(const byte_string &password);

        BIO *getPublicKey();

        BIO *getPrivateKey();

        ~DatabaseSecurityHeader();

    private:
        void setPublicKey(const byte *public_key_bytes);

        void setPrivateKey(const byte *private_key_bytes);
    };
}