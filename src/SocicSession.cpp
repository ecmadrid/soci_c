#include "SocicSession.h"

SocicSession::SocicSession()
{
    //ctor
    m_st = NULL;
    m_connectionString.assign("");
}

SocicSession::~SocicSession()
{
    //dtor
    Close();
}

void SocicSession::AddProperty(const string name, const string value)
{
    string newValue;
    newValue.assign(name).append("=").append(value);
    m_connectionString.append(" ").append(newValue);
    m_properties.push_back(newValue);
}


void SocicSession::Open()
{
    if (m_connectionString == "")
    {
        // Build connection string;
        for(auto & property : m_properties)
        {
            m_connectionString.append(" ").append(property);
        }
    }
#ifdef DEBUG
    cout << "***** [" << m_connectionString << "] *****" << endl;
#endif // DEBUG
    m_sql.open(GetProtocol(), m_connectionString);
}

void SocicSession::Close()
{
    if (m_st)
    {
        delete m_st;
        m_st = NULL;
    }

    m_sql.close();

    ClearProperties();
}

int SocicSession::GetNumFields()
{
    return m_row.size();
}

const string SocicSession::GetFieldName(int pos)
{
    const column_properties & props = m_row.get_properties(pos);
    return props.get_name();
}


void SocicSession::Execute(const string query)
{
    try
    {
        if (m_st)
        {
            delete m_st;
            m_st = NULL;
        }

        statement st = (m_sql.prepare<< query, into(m_row));
        m_st = new statement(st);
        m_st->execute();
    }
    catch(exception &ex)
    {
        cout << ex.what();
    }
}


void SocicSession::ExecuteNonQuery(const string sentence)
{
    m_sql.once << sentence;
}

bool SocicSession::Fetch()
{
    bool result = false;

    try
    {
        result = m_st->fetch();
    }
    catch(exception &ex)
    {
        cout << ex.what();
    }

    return result;
}

int SocicSession::GetFieldType(int pos)
{
    const column_properties & props = m_row.get_properties(pos);
    //return props.get_db_type();
    return props.get_data_type();
}

int SocicSession::GetFieldType(const string name)
{
    const column_properties & props = m_row.get_properties(name);
    //return props.get_db_type();
    return props.get_data_type();
}

bool SocicSession::GetFieldIsNull(int pos)
{
    indicator ind  = m_row.get_indicator(pos);
    return (ind == i_null);
}

bool SocicSession::GetFieldIsNull(const string name)
{
    indicator ind  = m_row.get_indicator(name);
    return (ind == i_null);
}

const string SocicSession::GetFieldAsString(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<string>(pos);

    return "";
}

const string SocicSession::GetFieldAsString(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<string>(name);

    return "";
}

double SocicSession::GetFieldAsDouble(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<double>(pos);

    return 0;
}

double SocicSession::GetFieldAsDouble(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<double>(name);

    return 0;
}

int8_t SocicSession::GetFieldAsInt8(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<int8_t>(pos);

    return 0;
}

int8_t SocicSession::GetFieldAsInt8(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<int8_t>(name);

    return 0;
}

uint8_t SocicSession::GetFieldAsUint8(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<uint8_t>(pos);

    return 0;
}

uint8_t SocicSession::GetFieldAsUint8(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<uint8_t>(name);

    return 0;
}

int16_t SocicSession::GetFieldAsInt16(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<int16_t>(pos);

    return 0;
}

int16_t SocicSession::GetFieldAsInt16(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<int16_t>(name);

    return 0;
}

uint16_t SocicSession::GetFieldAsUint16(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<uint16_t>(pos);

    return 0;
}

uint16_t SocicSession::GetFieldAsUint16(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<uint16_t>(name);

    return 0;
}

int32_t SocicSession::GetFieldAsInt32(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<int32_t>(pos);

    return 0;
}

int32_t SocicSession::GetFieldAsInt32(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<int32_t>(name);

    return 0;
}

uint32_t SocicSession::GetFieldAsUint32(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<uint32_t>(pos);

    return 0;
}

uint32_t SocicSession::GetFieldAsUint32(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<uint32_t>(name);

    return 0;
}

int64_t SocicSession::GetFieldAsInt64(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<int64_t>(pos);

    return 0;
}

int64_t SocicSession::GetFieldAsInt64(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<int64_t>(name);

    return 0;
}

uint64_t SocicSession::GetFieldAsUint64(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<uint64_t>(pos);

    return 0;
}

uint64_t SocicSession::GetFieldAsUint64(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<uint64_t>(name);

    return 0;
}

tm SocicSession::GetFieldAsTm(int pos)
{
    if (!GetFieldIsNull(pos))
        return m_row.get<tm>(pos);
}

tm SocicSession::GetFieldAsTm(const string name)
{
    if (!GetFieldIsNull(name))
        return m_row.get<tm>(name);
}

const string SocicSession::GetFieldAsFormatedDateString(int pos, const string format)
{
    if (!GetFieldIsNull(pos))
    {
        char buffer[100];
        tm time;
        time = GetFieldAsTm(pos);
        string result;
        strftime(buffer,sizeof(buffer),format.c_str(), &time);
        result.assign(buffer);
        return result;
    }

    return "";
}

const string SocicSession::GetFieldAsFormatedDateString(const string name, const string format)
{
    if (!GetFieldIsNull(name))
    {
        char buffer[100];
        tm time;
        time = GetFieldAsTm(name);
        string result;
        strftime(buffer,sizeof(buffer),format.c_str(), &time);
        result.assign(buffer);
        return result;
    }
    return "";
}

void SocicSession::ClearProperties()
{
    m_properties.clear();
}
