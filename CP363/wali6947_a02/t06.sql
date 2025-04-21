SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullMemberName,
    COUNT(p.pubId) AS numberOfBooks
FROM 
    member m
LEFT JOIN 
    pub p ON m.memberId = p.pubMemberId
JOIN 
    pubType pt ON p.pubPubType = pt.pubType
WHERE 
    pt.pubTypeDesc = 'Book' 
GROUP BY 
    m.memberId
ORDER BY 
    fullMemberName;
