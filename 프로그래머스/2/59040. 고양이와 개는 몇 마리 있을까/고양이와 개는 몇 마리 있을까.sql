-- 코드를 입력하세요
SELECT ANIMAL_TYPE, COUNT(*) AS count
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
HAVING ANIMAL_TYPE IN ('Cat', 'Dog')
ORDER BY ANIMAL_TYPE