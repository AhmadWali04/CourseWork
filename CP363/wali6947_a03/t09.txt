SELECT 
    m.memberSurname,
    m.memberForename,
    narrowExpertiseCounts.narrowCount
FROM 
    member m
JOIN (
    SELECT 
        mn.memberNarrowMemberId AS memberId,
        COUNT(mn.memberNarrowNarrowId) AS narrowCount
    FROM 
        memberNarrow mn
    GROUP BY 
        mn.memberNarrowMemberId
) AS narrowExpertiseCounts ON m.memberId = narrowExpertiseCounts.memberId
WHERE 
    narrowExpertiseCounts.narrowCount >= 30
ORDER BY 
    m.memberSurname, m.memberForename;
