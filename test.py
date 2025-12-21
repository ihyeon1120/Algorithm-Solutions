import psycopg2

conn = psycopg2.connect(
    host="localhost",
    port=5432,
    dbname="airflow_main",
    user="ihyeon",
    password="qpfflzk12"
)
print("✅ 연결 성공!")
conn.close()
