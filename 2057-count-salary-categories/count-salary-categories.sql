SELECT category, accounts_count
FROM (
    SELECT 'Low Salary' AS category,
           COUNT(*) AS accounts_count,
           2 AS ord
    FROM Accounts
    WHERE income < 20000

    UNION

    SELECT 'Average Salary',
           COUNT(*),
           3
    FROM Accounts
    WHERE income BETWEEN 20000 AND 50000

    UNION

    SELECT 'High Salary',
           COUNT(*),
           1
    FROM Accounts
    WHERE income > 50000
) t
ORDER BY ord;