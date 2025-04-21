SELECT DISTINCT
    m.memberSurname,
    m.memberForename,
    b.broadDesc
FROM 
    member m
JOIN 
    memberBroad mb ON m.memberId = mb.memberBroadMemberId
JOIN 
    broad b ON mb.memberBroadBroadId = b.broadId
WHERE 
    NOT EXISTS (
        SELECT 1
        FROM pub p
        WHERE p.pubMemberId = m.memberId
    )
ORDER BY 
    m.memberSurname,
    m.memberForename,
    b.broadDesc;
