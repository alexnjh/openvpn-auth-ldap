#ifndef OPENVPN_PI_H
#define OPENVPN_PI_H

#define MAXPASSWORDLENGTH 100
#define MAXOTPLENGTH 6

typedef struct
{
	char password[MAXPASSWORDLENGTH];
	char otp[MAXOTPLENGTH];
} privacyidea_response;

/* Parse a string containing a account password + 6 digit OTP pin and store the result
   into an privacyidea_response struct.
   If parsing succeeds result will be in result and 1 is returned.
   If parsing fails, 0 is returned, error_message is set */
int extract_privacyidea_otp_and_password(const char *response, privacyidea_response *result, char **error_message);

#endif