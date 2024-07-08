#ifndef SOCICSESSION_H
#define SOCICSESSION_H

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

#include <iostream>
#include <string>
#include <vector>
#include <soci/soci.h>

using namespace std;
using namespace soci;

class SocicSession
{
public:
    SocicSession();
    virtual ~SocicSession();
    void SetProtocol(const string value)
    {
        m_protocol.assign(value);
    }
    void AddProperty(const string name, const string value);

    void SetConnectionString( const string value)
    {
        m_connectionString = value;
    }

    const string GetProtocol()
    {
        return m_protocol;
    }
    const string GetConnectionString()
    {
        return m_connectionString;
    }
    void Execute(const string query);
    void ExecuteNonQuery(const string sentence);
    bool Fetch();

    void Open();
    void Close();

    int GetNumFields();

    int GetFieldType(int pos);
    int GetFieldType(const string name);


    bool GetFieldIsNull(int pos);
    bool GetFieldIsNull(const string name);

    const string GetFieldName(int pos);

    const string GetFieldAsString(int pos);
    const string GetFieldAsString(const string name);
    double GetFieldAsDouble(int pos);
    double GetFieldAsDouble(const string name);
    int8_t GetFieldAsInt8(int pos);
    int8_t GetFieldAsInt8(const string name);
    uint8_t GetFieldAsUint8(int pos);
    uint8_t GetFieldAsUint8(const string name);
    int16_t GetFieldAsInt16(int pos);
    int16_t GetFieldAsInt16(const string name);
    uint16_t GetFieldAsUint16(int pos);
    uint16_t GetFieldAsUint16(const string name);
    int32_t GetFieldAsInt32(int pos);
    int32_t GetFieldAsInt32(const string name);
    uint32_t GetFieldAsUint32(int pos);
    uint32_t GetFieldAsUint32(const string name);
    int64_t GetFieldAsInt64(int pos);
    int64_t GetFieldAsInt64(const string name);
    uint64_t GetFieldAsUint64(int pos);
    uint64_t GetFieldAsUint64(const string name);
    tm GetFieldAsTm(int pos);
    tm GetFieldAsTm(const string name);
    const string GetFieldAsFormatedDateString(int pos, const string format);
    const string GetFieldAsFormatedDateString(const string name, const string format);
    void ClearProperties();

protected:

private:
    session m_sql;
    row m_row;
    statement *m_st;
    vector<string> m_properties;
    string m_protocol;
    string m_connectionString;
};

#endif // SOCICSESSION_H
