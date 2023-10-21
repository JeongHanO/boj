-- 코드를 입력하세요
SELECT YEAR(B.SALES_DATE) AS YEAR, MONTH(B.SALES_DATE) AS MONTH, A.GENDER, COUNT(DISTINCT A.USER_ID) AS USERS
FROM USER_INFO A JOIN ONLINE_SALE B ON A.USER_ID = B.USER_ID
WHERE GENDER IS NOT NULL
GROUP BY YEAR(B.SALES_DATE), MONTH(B.SALES_DATE), A.GENDER
ORDER BY YEAR(B.SALES_DATE), MONTH(B.SALES_DATE), A.GENDER