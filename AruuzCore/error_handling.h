#ifndef _errorhandling_h
#define _errorhandling_h

typedef enum _config_error
{
    E_SUCCESS = 0,
    E_INVALID_INPUT,
	E_ZERO_LEN_INIT
}error_t;

typedef enum _error_source
{
    S_DEFUALT = 0,
	S_MET_NEW
}source_t;

extern struct _errordesc {
    int  code;
    char *message;
};

extern error_t err_code;
extern source_t err_source;
extern struct _errordesc errordesc[];
extern struct _errordesc sourcedesc[];

#endif