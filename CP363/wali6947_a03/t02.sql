SELECT 
    m.memberSurname,
    m.memberForename,
    COUNT(DISTINCT mb.memberBroadBroadId) AS broadCount,
    COUNT(DISTINCT mn.memberNarrowNarrowId) AS narrowCount
FROM 
    member m
LEFT JOIN 
    memberBroad mb ON m.memberId = mb.memberBroadMemberId
LEFT JOIN 
    memberNarrow mn ON m.memberId = mn.memberNarrowMemberId
GROUP BY 
    m.memberSurname,
    m.memberForename
ORDER BY 
    m.memberSurname, m.memberForename;
