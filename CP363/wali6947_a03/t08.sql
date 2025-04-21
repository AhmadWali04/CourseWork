SELECT 
    m.memberSurname,
    m.memberForename,
    broadExpertiseCounts.broadCount
FROM 
    member m
JOIN (
    SELECT 
        mb.memberBroadBroadId,
        COUNT(mb.memberBroadBroadId) AS broadCount
    FROM 
        memberBroad mb
    GROUP BY 
        mb.memberBroadBroadId
) AS broadExpertiseCounts ON m.memberId = broadExpertiseCounts.memberBroadBroadId
WHERE 
    broadExpertiseCounts.broadCount >= 8
ORDER BY 
    m.memberSurname, m.memberForename
