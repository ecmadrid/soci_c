#include <soci_c.h>
#include <SocicSession.h>

EXPORT soci_session soci_c_create_session(const char *protocol)
{
    SocicSession *session = new SocicSession();
    session->SetProtocol(protocol);
    return session;
}

void EXPORT soci_c_delete_session(soci_session session)
{
    delete static_cast<SocicSession*>(session);
}

EXPORT void soci_c_add_property(soci_session session, const char *name, const char *value)
{
    static_cast<SocicSession*>(session)->AddProperty(name, value);
}

EXPORT const char *soci_c_get_protocol(soci_session session)
{
    return static_cast<SocicSession*>(session)->GetProtocol().data();
}

EXPORT const char *soci_c_get_connection_string(soci_session session)
{
    return static_cast<SocicSession*>(session)->GetConnectionString().data();
}


EXPORT void soci_c_open(soci_session session)
{
    static_cast<SocicSession*>(session)->Open();
}

EXPORT void soci_c_close(soci_session session)
{
    static_cast<SocicSession*>(session)->Close();
}

EXPORT void soci_c_execute(soci_session session, const char *query)
{
    static_cast<SocicSession*>(session)->Execute(query);
}

EXPORT void soci_c_execute_non_query(soci_session session, const char *sentence)
{
    static_cast<SocicSession*>(session)->ExecuteNonQuery(sentence);
}

int soci_c_num_fields(soci_session session)
{
    return static_cast<SocicSession*>(session)->GetNumFields();
}

char* soci_get_name_idx(soci_session session, int pos)
{
    const char *fieldName = static_cast<SocicSession*>(session)->GetFieldName(pos).data();
    char *result = NULL;



    int len = strlen(fieldName) +1;
    result = (char *)malloc(len * sizeof(char));
    memset(result, 0,len);
    strcpy(result, fieldName);

    return result;
}

EXPORT bool soci_c_fetch(soci_session session)
{
    return  static_cast<SocicSession*>(session)->Fetch();
}

EXPORT int soci_c_get_type_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldType(pos);
}

EXPORT int soci_c_get_type(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldType(name);
}

EXPORT bool soci_c_is_null_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldIsNull(pos);
}

EXPORT bool soci_c_is_null(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldIsNull(name);
}


EXPORT char *soci_c_get_as_string_idx(soci_session session, int pos, char **oldValue)
{
    const char *fieldValue = static_cast<SocicSession*>(session)->GetFieldAsString(pos).data();
    char *result = NULL;

    if(oldValue)
    {
        result = *oldValue;
        if(result)
        {
            free(result);

        }
    }

    int len = strlen(fieldValue) +1;
    result = (char *)malloc(len * sizeof(char));
    memset(result, 0,len);
    strcpy(result, fieldValue);

    if(oldValue)
    {
        *oldValue = result;
    }

    return result;
}

EXPORT char *soci_c_get_as_string(soci_session session, const char *name, char **oldValue)
{
    const char *fieldValue = static_cast<SocicSession*>(session)->GetFieldAsString(name).data();
    char *result = NULL;

    if(oldValue)
    {
        result = *oldValue;
        if(result)
        {
            free(result);

        }
    }

    int len = strlen(fieldValue) +1;
    result = (char *)malloc(len * sizeof(char));
    memset(result, 0,len);
    strcpy(result, fieldValue);

    if(oldValue)
    {
        *oldValue = result;
    }

    return result;
}

EXPORT double soci_c_get_as_double_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsDouble(pos);
}

EXPORT double soci_c_get_as_double(soci_session session, const char *name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsDouble(name);
}

EXPORT signed char soci_c_get_as_int8_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt8(pos);
}

EXPORT signed char soci_c_get_as_int8(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt8(name);
}

EXPORT char soci_c_get_as_uint8_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint8(pos);
}

EXPORT char soci_c_get_as_uint8(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint8(name);
}

EXPORT short soci_c_get_as_int16_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt16(pos);
}

EXPORT short soci_c_get_as_int16(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt16(name);
}

EXPORT unsigned short soci_c_get_as_uint16_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint16(pos);
}

EXPORT unsigned short soci_c_get_as_uint16(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint16(name);
}

EXPORT int soci_c_get_as_int32_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt32(pos);
}

EXPORT int soci_c_get_as_int32(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt32(name);
}

EXPORT unsigned int soci_c_get_as_uint32_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint32(pos);
}

EXPORT unsigned int soci_c_get_as_uint32(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint32(name);
}

EXPORT long long soci_c_get_as_int64_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt64(pos);
}

EXPORT long long soci_c_get_as_int64(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsInt64(name);
}

EXPORT unsigned long long soci_c_get_as_uint64_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint64(pos);
}

EXPORT unsigned long long soci_c_get_as_uint64(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsUint64(name);
}

EXPORT struct tm soci_c_get_as_tm_idx(soci_session session, int pos)
{
    return static_cast<SocicSession*>(session)->GetFieldAsTm(pos);
}

EXPORT struct tm soci_c_get_as_tm(soci_session session, const char* name)
{
    return static_cast<SocicSession*>(session)->GetFieldAsTm(name);
}

char* soci_c_get_as_formated_date_string_idx(soci_session session, int pos, const char* format, char **oldValue)
{
    const char *fieldValue = static_cast<SocicSession*>(session)->GetFieldAsFormatedDateString(pos, format).data();
    char *result = NULL;

    if(oldValue)
    {
        result = *oldValue;
        if(result)
        {
            free(result);

        }
    }

    int len = strlen(fieldValue) +1;
    result = (char *)malloc(len * sizeof(char));
    memset(result, 0,len);
    strcpy(result, fieldValue);

    if(oldValue)
    {
        *oldValue = result;
    }

    return result;
}

char* soci_c_get_as_formated_date_string(soci_session session, const char* name, const char* format, char **oldValue)
{
    const char *fieldValue = static_cast<SocicSession*>(session)->GetFieldAsFormatedDateString(name, format).data();
    char *result = NULL;

    if(oldValue)
    {
        result = *oldValue;
        if(result)
        {
            free(result);

        }
    }

    int len = strlen(fieldValue) +1;
    result = (char *)malloc(len * sizeof(char));
    memset(result, 0,len);
    strcpy(result, fieldValue);

    if(oldValue)
    {
        *oldValue = result;
    }

    return result;
}

void soci_clear_properties(soci_session session)
{
    static_cast<SocicSession*>(session)->ClearProperties();
}
