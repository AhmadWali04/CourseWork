SELECT DISTINCT
    m.memberSurname,
    m.memberForename,
    n.narrowDesc AS narrowExpertise
FROM 
    member m
JOIN 
    memberNarrow mn ON m.memberId = mn.memberNarrowMemberId
JOIN 
    narrow n  ON mn.memberNarrowMemberId = n.narrowId
JOIN 
    broad b ON n.narrowBroadId = b.broadId
WHERE 
    b.broadDesc = 'Environmental Security'
    AND NOT EXISTS (
        SELECT broadDesc
        FROM memberBroad 
        JOIN broad AS broad_check ON memberBroad.memberBroadBroadId = broad_check.broadId
        WHERE 
            memberBroad.memberBroadBroadId = m.memberId
            AND broad_check.broadDesc = 'Environmental Security'
    )
ORDER BY 
    m.memberSurname, m.memberForename;
