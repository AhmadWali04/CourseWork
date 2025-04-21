SELECT 
    n.narrowDesc AS narrowExpertiseDescription,
    COUNT(mn.memberNarrowMemberId) AS numberOfMembers
FROM 
    narrow n
LEFT JOIN 
    memberNarrow mn ON n.narrowId = mn.memberNarrowMemberId
GROUP BY 
    n.narrowId
ORDER BY 
    narrowExpertiseDescription
