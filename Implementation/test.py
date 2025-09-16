import datetime
import time

# 오늘의 날짜를 가져옵니다.
today_date = datetime.date.today()

# 오늘 날짜의 0시 0분 0초에 해당하는 datetime 객체를 생성합니다.
start_of_today = datetime.datetime.combine(today_date, datetime.time.min)

# datetime 객체를 유닉스 타임스탬프(초)로 변환합니다.
start_of_today_timestamp = int(start_of_today.timestamp())

print(f"오늘의 시작 시간 (초): {start_of_today_timestamp}")
# 예시 출력 (2025년 9월 9일 기준): 오늘의 시작 시간 (초): 1725807600