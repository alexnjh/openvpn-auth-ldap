#include "privacyidea-otp.h"
#include <string.h>

char * last_n( const char *s, size_t n )
{
    size_t length = strlen( s );

    return ( char * )( length < n ? s : s + length - n );
} 

int set_password(const char * source, char * destination)
{
	size_t length = strlen(source);
	if (length >= MAXPASSWORDLENGTH)
		return 0;
	strncpy(destination, source, length-MAXOTPLENGTH);
	return 1;
}

int set_otp(const char * source, char * destination)
{
	if (strlen(source) < MAXOTPLENGTH)
		return 0;
	destination = last_n(source, MAXOTPLENGTH);
	return 1;
}

int extract_privacyidea_otp_and_password(const char *response, privacyidea_response *result, char **error_message)
{

    if (response != NULL){
		size_t length = strlen(response);
		if (length == 0){
			*error_message = "Password length too short, OTP pin might be missing";
			return 0;		
		}else{

			if (!set_password(response, result->password)){
				*error_message = "Unable to set password information.";
				return 0;
			}

			if (!set_otp(response, result->otp)){
				*error_message = "Unable to set otp information.";
				return 0;
			}
			return 1;
		}

	}else{
		*error_message = "Incorrectly formatted or empty password string.";
		return 0;		
	}
}


