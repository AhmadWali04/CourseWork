SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullMemberName,
    COUNT(p.pubId) AS numberOfPublications
FROM 
    member m
LEFT JOIN 
    pub p ON m.memberId = p.pubMemberId
GROUP BY 
    m.memberId
ORDER BY 
    fullMemberName
