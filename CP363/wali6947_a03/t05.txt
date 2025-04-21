SELECT 
    m.memberSurname,
    m.memberForename,
    pubCount
FROM 
    member m
JOIN 
    (SELECT 
        pubMemberId,
        COUNT(pubId) AS pubCount
    FROM 
        pub
    GROUP BY 
        pubMemberId
) AS publicationCounts ON m.memberId = publicationCounts.pubMemberId
WHERE 
    pubCount >= 4
ORDER BY 
    m.memberSurname, m.memberForename;
