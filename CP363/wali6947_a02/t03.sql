SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullName,
    p.pubTitle AS publicationTitle
FROM 
    member m
JOIN 
    pub p ON m.memberId = p.pubMemberId
WHERE 
    p.pubTitle LIKE '%Nuclear%'
ORDER BY 
    publicationTitle
