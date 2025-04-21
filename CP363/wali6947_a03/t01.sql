SELECT 
    m.memberSurname,
    m.memberForename,
    SUM(CASE WHEN pt.pubType = 'B' THEN 1 ELSE 0 END) AS books,
    SUM(CASE WHEN pt.pubType = 'A' THEN 1 ELSE 0 END) AS articles,
    SUM(CASE WHEN pt.pubType = 'P' THEN 1 ELSE 0 END) AS papers
FROM 
    member m
JOIN 
    pub p ON m.memberId = p.pubMemberId
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
GROUP BY 
    m.memberSurname,
    m.memberForename
ORDER BY 
     m.memberSurname, m.memberForename;
