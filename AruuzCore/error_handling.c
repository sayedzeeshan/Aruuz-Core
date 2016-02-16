#include"error_handling.h"

struct _errordesc errordesc[] = {
    { E_SUCCESS, "No error" },
    { E_INVALID_INPUT, "Invalid input" },
	{ E_ZERO_LEN_INIT, "Zero length initilization" }
};

struct _errordesc sourcedesc[] = {
    { S_DEFUALT, "No source specified" },
	{ S_MET_NEW, "meter_new, [meters.c]"}
};

error_t err_code = E_SUCCESS;
source_t err_source = S_DEFUALT;