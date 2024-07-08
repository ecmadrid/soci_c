#ifndef SOCI_C_H_INCLUDED
#define SOCI_C_H_INCLUDED

#if defined(_MSC_VER)
//  Microsoft
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
//  do nothing and hope for the best?
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#include <stdbool.h>
#include <time.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

enum DB_TYPE
{
    DB_STRING,
    DB_INT8,
    DB_UINT8,
    DB_INT16,
    DB_UINT16,
    DB_INT32,
    DB_UINT32,
    DB_INT64,
    DB_UINT64,
    DB_DOUBLE,
    DB_DATE,
    DB_BLOB,
    DB_XML
};

// Soci_c interface definition.

typedef void* soci_session;

/** \brief Creates a Soci session for selected protocol.
 *
 * \param protocol const char*
 * \return EXTERNC EXPORT soci_session
 *
 */
EXTERNC EXPORT soci_session soci_c_create_session(const char *protocol);

/** \brief Deletes a Soci session.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_delete_session(soci_session session);


/** \brief Adds a property for connection string.
 *
 * \param session soci_session
 * \param name const char*
 * \param value const char*
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_add_property(soci_session session, const char *name, const char *value);

/** \brief Returns Soci connection protocol.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT const char*
 *
 */
EXTERNC EXPORT const char* soci_c_get_protocol(soci_session session);

/** \brief Returns Soci connection string.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT const char*
 *
 */
EXTERNC EXPORT const char* soci_c_get_connection_string(soci_session session);

#endif // SOCI_C_H_INCLUDED

/** \brief Opens a Soci connection.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_open(soci_session session);

/** \brief Closes a Soci connection.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_close(soci_session session);

/** \brief Executes a query to get results.
 *
 * \param session soci_session
 * \param query const char*
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_execute(soci_session session, const char *query);

/** \brief Executes a sentence without results.
 *
 * \param session soci_session
 * \param sentence const char*
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_c_execute_non_query(soci_session session, const char *sentence);

/** \brief Fetchs data. Returns false on end or not data.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT bool
 *
 */
EXTERNC EXPORT bool soci_c_fetch(soci_session session);

/** \brief Returns numer of fields.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT int
 *
 */
EXTERNC EXPORT int soci_c_num_fields(soci_session session);

/** \brief Returns field name at pos. Calling must free return value.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT char*
 *
 */
EXTERNC EXPORT char *soci_get_name_idx(soci_session session, int pos);

/** \brief Returns data type of field at pos.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT int
 *
 */
EXTERNC EXPORT int soci_c_get_type_idx(soci_session session, int pos);

/** \brief Returns data type of field with name.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT int
 *
 */
EXTERNC EXPORT int soci_c_get_type(soci_session session, const char *name);

/** \brief Returns true/false value for field at pos.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT bool
 *
 */
EXTERNC EXPORT bool soci_c_is_null_idx(soci_session session, int pos);

/** \brief Returns true/false value for field with name.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT bool
 *
 */
EXTERNC EXPORT bool soci_c_is_null(soci_session session, const char *name);

/** \brief Returns value of field at pos as string. Calling must free return value.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT char**
 *
 */
EXTERNC EXPORT char *soci_c_get_as_string_idx(soci_session session, int pos, char **oldValue);

/** \brief Returns value of field with name as string. Calling must free return value.
 *
 * \param session soci_session
 * \param name const char*
  * \param oldValue char**
 * \return EXTERNC EXPORT char**
 *
 */
EXTERNC EXPORT char *soci_c_get_as_string(soci_session session, const char *name, char **oldValue);

/** \brief Returns value of field at pos as double.
 *
 * \param session soci_session
 * \param pos int
  * \param oldValue char*
 * \return EXTERNC EXPORT double
 *
 */
EXTERNC EXPORT double soci_c_get_as_double_idx(soci_session session, int pos);

/** \brief Returns value of field with name as double.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT double
 *
 */
EXTERNC EXPORT double soci_c_get_as_double(soci_session session, const char *name);

/** \brief Returns value of field at pos as int8.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT signed char
 *
 */
EXTERNC EXPORT signed char soci_c_get_as_int8_idx(soci_session session, int pos);

/** \brief Returns value of field with name as int8.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT signed char
 *
 */
EXTERNC EXPORT signed char soci_c_get_as_int8(soci_session session, const char *name);

/** \brief Returns value of field at pos as uint8.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT char
 *
 */
EXTERNC EXPORT char soci_c_get_as_uint8_idx(soci_session session, int pos);

/** \brief Returns value of field with name as uint8.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT char
 *
 */
EXTERNC EXPORT char soci_c_get_as_uint8(soci_session session, const char *name);

/** \brief Returns value of field at pos as int16.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT short
 *
 */
EXTERNC EXPORT short soci_c_get_as_int16_idx(soci_session session, int pos);

/** \brief Returns value of field with name as int16.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT short
 *
 */
EXTERNC EXPORT short soci_c_get_as_int16(soci_session session, const char *name);

/** \brief Returns value of field at pos as uint16.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT unsigned short
 *
 */
EXTERNC EXPORT unsigned short soci_c_get_as_uint16_idx(soci_session session, int pos);

/** \brief Returns value of field with name as uint16.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT unsigned short
 *
 */
EXTERNC EXPORT unsigned short soci_c_get_as_uint16(soci_session session, const char *name);

/** \brief Returns value of field at pos as int32.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT int
 *
 */
EXTERNC EXPORT int soci_c_get_as_int32_idx(soci_session session, int pos);

/** \brief Returns value of field with name as int32.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT int
 *
 */
EXTERNC EXPORT int soci_c_get_as_int32(soci_session session, const char *name);

/** \brief Returns value of field at pos as uint32.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT unsigned int
 *
 */
EXTERNC EXPORT unsigned int soci_c_get_as_uint32_idx(soci_session session, int pos);

/** \brief Returns value of field with name as uint32.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT unsigned int
 *
 */
EXTERNC EXPORT unsigned int soci_c_get_as_uint32(soci_session session, const char *name);

/** \brief Returns value of field at pos as int64.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT long long
 *
 */
EXTERNC EXPORT long long soci_c_get_as_int64_idx(soci_session session, int pos);

/** \brief Returns value of field with name as int64.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT long long
 *
 */
EXTERNC EXPORT long long soci_c_get_as_int64(soci_session session, const char *name);

/** \brief Returns value of field at pos as uint64.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT unsigned long long
 *
 */
EXTERNC EXPORT unsigned long long soci_c_get_as_uint64_idx(soci_session session, int pos);

/** \brief Returns value of field with name as uint64.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT unsigned long long
 *
 */
EXTERNC EXPORT unsigned long long soci_c_get_as_uint64(soci_session session, const char *name);

/** \brief Returns value of field at pos as tm struct.
 *
 * \param session soci_session
 * \param pos int
 * \return EXTERNC EXPORT struct tm
 *
 */
EXTERNC EXPORT struct tm soci_c_get_as_tm_idx(soci_session session, int pos);

/** \brief Returns value of field with name as tm struct.
 *
 * \param session soci_session
 * \param name const char*
 * \return EXTERNC EXPORT struct tm
 *
 */
EXTERNC EXPORT struct tm soci_c_get_as_tm(soci_session session, const char *name);

/** \brief Returns string with formated field date value at pos. Calling must free return value.
 *
 * \param session soci_session
 * \param pos int
 * \param format const char*
  * \param oldValue char*
 * \return EXTERNC EXPORT char*
 *
 */
EXTERNC EXPORT char *soci_c_get_as_formated_date_string_idx(soci_session session, int pos, const char *format, char **oldValue);

/** \brief Returns string with formated field date value with name. Calling must free return value.
 *
 * \param session soci_session
 * \param name const char*
 * \param format const char*
  * \param oldValue char*
 * \return EXTERNC EXPORT char*
 *
 */
EXTERNC EXPORT char *soci_c_get_as_formated_date_string(soci_session session, const char *name, const char *format, char **oldValue);

/** \brief Clears properties.
 *
 * \param session soci_session
 * \return EXTERNC EXPORT void
 *
 */
EXTERNC EXPORT void soci_clear_properties(soci_session session);

#undef EXTERNC
